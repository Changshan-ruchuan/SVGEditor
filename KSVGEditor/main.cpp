#include <QtWidgets/QApplication>
#include <QDesktopwidget>

#include "ksvgeditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget *desktop = QApplication::desktop();
    KSVGEditor w;
    // �������ƶ��������м�
    w.move((desktop->width() - w.width()) / 2, (desktop->height() - w.height()) / 2);
    w.show();
    return a.exec();
}
