#include <QApplication>
#include <QDesktopWidget>
#include <QTranslator>
#include <DGuiApplicationHelper>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator m_translatorLanguage = new QTranslator(this);
    m_translatorLanguage->load("/usr/share/dde-control-center/translations/keyboard_language_" + QLocale::system().name());
    app->installTranslator(m_translatorLanguage);

    return app.exec();
}
