#include "QtThread1.h"
#include <QDebug>
#include <QLabel>
#include <QPalette>
#include <QLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>

#include "thumbNailThread.h"

QtThread1::QtThread1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	waitseconds = 1;
	QPalette pal = palette();//QPalette 调色板类，专门用于管理对话框的外观显示
	pal.setColor(QPalette::Background, Qt::white);

	//setFixedSize(600, 400);
	setWindowTitle("www.cuteqt.com");
	previewwidget = new QWidget(this);
	previewwidget->setPalette(pal);
	previewwidget->setAutoFillBackground(true);
	previewwidget->setFixedSize(600, 400);
	QPushButton* btn = new QPushButton("Open pictures..", this);
	btn->setGeometry(1000,800, 130, 35);
	connect(btn, SIGNAL(clicked()), this, SLOT(openFiles()));

	QGridLayout* layout = new QGridLayout(previewwidget);

}

void QtThread1::openFiles()
{
	waitseconds = 1;//reset

	QStringList list = QFileDialog::getOpenFileNames(this, "Open one or more pictures", "", "*.jpg *.png *.bmp");
	if (list.count() == 0)
	{
		return;
	}

	processDialog = new QProgressDialog(this);
	processDialog->setWindowModality(Qt::WindowModal);
	processDialog->setWindowTitle(tr("Please Wait"));
	processDialog->setLabelText(tr("Opening..."));
	processDialog->setCancelButtonText(tr("Cancel"));
	//processDialog->setMinimumDuration(100);//预估时间，若大于这个时间才出现对话框
	processDialog->setRange(0,list.length());

	processValue = 0;
	processDialog->setValue(processValue);
	processDialog->show();

	//open files one by one, and create thread to create thumbnail for each file
	QStringList::Iterator it = list.begin();
	while (it != list.end())
	{
		createThumbnail(*it);
		++it;
	}
}

void QtThread1::createThumbnail(const QString& filename)
{
	qDebug() << filename;
	QThread* thread = new ThumbnailThread(filename, 10 - waitseconds);
	waitseconds++;
	connect(thread, SIGNAL(thumbnailFinished(QImage)), this, SLOT(addThumbnail(QImage)));
	connect(thread, SIGNAL(thumbnailFailed(const QString)), this, SLOT(showError(const QString)));
	connect(thread, SIGNAL(finished()), this, SLOT(deleteThread()));
	thread->start();
}

void QtThread1::deleteThread()
{
	QObject* obj = sender();
	ThumbnailThread * th = qobject_cast<ThumbnailThread*>(obj);
	qDebug() << "delete thread..." << th->waitseconds();
	obj->deleteLater();
	processValue++;
	processDialog->setValue(processValue);
}

void QtThread1::addThumbnail(QImage smallpm)
{
	static int i = 0;
	static int j = 0;

	qWarning() << "thumbnail create successfully..." << j << i;
	qWarning() << "Small PM:" << smallpm << smallpm.size();
	QLabel* label = new QLabel;
	label->setPixmap(QPixmap::fromImage(smallpm));
	QGridLayout* gl = qobject_cast<QGridLayout*>(previewwidget->layout());
	gl->addWidget(label, j, i);//j 行 i列
	label->show();
	qWarning() << "Label:" << label << label->isVisible();
	i++;
	if (i > this->width() / smallpm.width())
	{
		i = 0;
		j++;
	}
}

void QtThread1::showError(const QString filename)
{
	QMessageBox::information(this, "Error!", filename + " is not a valid picture file.");
}

