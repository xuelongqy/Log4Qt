#include <QDateTime>
#include <QDebug>
#include <QDir>
#include "logger.h"

LogConfig Logger::logConfig = LogConfig();

void Logger::setLogConfig(LogConfig config)
{
    Logger::logConfig = config;
}

void Logger::log(LogType type, QString msg)
{
    // 生成日志
    QString logMsg = getLogMsg(type, msg);
    // 控制台
    if (logConfig.outConsole && type >= logConfig.consoleType) {
        qDebug() << logMsg;
    }
    // 文件
    if (logConfig.outFile && type >= logConfig.fileType) {
        // 追加写入
        QFile logFile(getFile());
        if (logFile.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append)) {
            QTextStream in(&logFile);
            in << logMsg << "\n";
            in.flush();
            logFile.close();
        }
    }
}

void Logger::d(QString msg)
{
    Logger::log(LogType::DEBUG, msg);
}

void Logger::i(QString msg)
{
    Logger::log(LogType::INFO, msg);
}

void Logger::w(QString msg)
{
    Logger::log(LogType::WARNING, msg);
}

void Logger::e(QString msg)
{
    Logger::log(LogType::ERROR, msg);
}

QString Logger::getLogPath()
{
    return QDir(Logger::logConfig.path).absolutePath();
}

QString Logger::getDate()
{
    // 获取当前日期
    QDateTime current_date_time =QDateTime::currentDateTime();
    return current_date_time.toString(logConfig.dataType);
}

QString Logger::getLogMsg(LogType type, QString msg)
{
    // 按照规则生成日志
    QString logMsg = logConfig.pattern;
    // 日期
    logMsg.replace("%D", getDate());
    // 类型
    logMsg.replace("%T", getLogTypeName(type));
    // 内容
    logMsg.replace("%M", msg);
    return logMsg;
}

QString Logger::getFile()
{
    // 获取当前日期
    QDateTime current_date_time =QDateTime::currentDateTime();
    // 获取文件名字
    QString fileName = current_date_time.toString("yyyy-MM-dd") + ".log";
    // 日志文件夹
    QDir pathDir(logConfig.path);
    // 判断文件夹路径是否存在
    if (!pathDir.exists()) {
        pathDir.mkpath(logConfig.path);
    }
    return pathDir.absoluteFilePath(fileName);
}

QString Logger::getLogTypeName(LogType type)
{
    if (type == LogType::DEBUG) {
        return "[DEBUG]";
    }else if (type == LogType::INFO) {
        return "[INFO]";
    }else if (type == LogType::WARNING) {
        return "[WARNING]";
    }else if (type == LogType::ERROR) {
        return "[ERROR]";
    }else {
        return "";
    }
}
