#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>

#include <logger.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // 配置日志
    Logger::logConfig.path = QDir::homePath() + "/" + "Log4Qt" + "/" + "log";
    Logger::logConfig.fileType = LogType::WARNING;

    QGuiApplication app(argc, argv);

    // 将日志对象注入Qml
    qmlRegisterType<Logger>("com.knoyo.logger", 1, 0, "Logger");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    // 使用Logger
    Logger::d("main.cpp -> App start!");

    return app.exec();
}
