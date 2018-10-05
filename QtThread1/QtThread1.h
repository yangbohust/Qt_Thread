#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtThread1.h"
#include <QTimer>
#include <QImage>
#include<qprogressdialog.h>

class QPushButton;
class QLabel;


class QtThread1 : public QMainWindow
{
	Q_OBJECT

public:
	QtThread1(QWidget *parent = Q_NULLPTR);

protected slots:
	void openFiles();
	void deleteThread();
	void showError(const QString filename);
	void addThumbnail(QImage);
private:
	void createThumbnail(const QString& filename);
	QWidget* previewwidget;//图像略缩图预览窗口
	int waitseconds;
	QProgressDialog* processDialog;
	int processValue;//进度条进度值


private:
	Ui::QtThread1Class ui;
};
