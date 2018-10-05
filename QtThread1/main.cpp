#include "QtThread1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtThread1 w;
	w.show();
	return a.exec();
}
