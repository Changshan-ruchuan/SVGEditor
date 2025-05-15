#include <QtWidgets/QApplication>
#include <QDesktopwidget>

#include "ksvgeditor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDesktopWidget *desktop = QApplication::desktop();
    KSVGEditor w;
    w.move((desktop->width() - w.width()) / 2, (desktop->height() - w.height()) / 2);
    w.show();
    return app.exec();
}
