﻿#ifndef LOGGER_H
#define LOGGER_H

#define LOG_ERROR(x)  Logger::e(QVariant(QString(__FILE__)+" : "+QString(__func__)+" : "+QString::number(__LINE__)+" # "+QVariant(x).toString()))
#define LOG_INFO(x)  Logger::i(QVariant(QString(__FILE__)+" : "+QString(__func__)+" : "+QString::number(__LINE__)+" # "+QVariant(x).toString()))
#define LOG_DEBUG(x)  Logger::d(QVariant(QString(__FILE__)+" : "+QString(__func__)+" : "+QString::number(__LINE__)+" # "+QVariant(x).toString()))
#define LOG_WARM(x)  Logger::w(QVariant(QString(__FILE__)+" : "+QString(__func__)+" : "+QString::number(__LINE__)+" # "+QVariant(x).toString()))


#include <QString>
#include <QFile>
#include <QVariant>


// 日志类型枚举
enum LogType {LOG_DEBUG=1, LOG_INFO=2, LOG_WARNING=3, LOG_ERROR=4};
// 配置结构体
struct LogConfig
{
    // 日志路径,默认当前目录的log文件夹内,配置输出文件后生效
    QString path = "./log";
    // 日期格式
    QString dataType = "yyyy-MM-dd hh:mm:ss:zzz";
    // 输出规则
    QString pattern = "%D %T %M";
    // 控制台配置
    bool outConsole = true;
    LogType consoleType = LogType::LOG_DEBUG;
    // 文件配置
    bool outFile = true;
    LogType fileType = LogType::LOG_DEBUG;
};

class  Logger: public QObject
{
    Q_OBJECT
public:
    // 日志配置
    static LogConfig logConfig;

    /**
     * @Title: setConfig方法
     * @Class: Logger
     * @Description: 设置日志配置
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:22:54
     * @update_author
     * @update_time
     * @version V1.0
     * @param config [LogConfig] 日志配置
     * @return
    */
    static void setLogConfig(LogConfig config);

    /**
     * @Title: log方法
     * @Class: Logger
     * @Description: 输出日志
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:24:01
     * @update_author
     * @update_time
     * @version V1.0
     * @param type [LogType] 类型
     * @param msg [QString] 日志内容
     * @return
    */
    Q_INVOKABLE static void log(LogType type, QString msg);

    /**
     * @Title: d方法
     * @Class: Logger
     * @Description: 输入Debug日志
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:25:22
     * @update_author
     * @update_time
     * @version V1.0
     * @param msg [QVariant] 日志内容
     * @return
    */
//    Q_INVOKABLE static void d(QString msg);
    Q_INVOKABLE static void d(QVariant msg);

    /**
     * @Title: d方法
     * @Class: Logger
     * @Description: 输入Info日志
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:25:22
     * @update_author
     * @update_time
     * @version V1.0
     * @param msg [QVariant] 日志内容
     * @return
    */
    Q_INVOKABLE static void i(QVariant msg);

    /**
     * @Title: d方法
     * @Class: Logger
     * @Description: 输入Warning日志
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:25:22
     * @update_author
     * @update_time
     * @version V1.0
     * @param msg [QVariant] 日志内容
     * @return
    */
    Q_INVOKABLE static void w(QVariant msg);

    /**
     * @Title: d方法
     * @Class: Logger
     * @Description: 输入Error日志
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:25:22
     * @update_author
     * @update_time
     * @version V1.0
     * @param msg [QVariant] 日志内容
     * @return
    */
    Q_INVOKABLE static void e(QVariant msg);

    /**
     * @Title: getLogPath方法
     * @Class: Logger
     * @Description: 获取日志保存路径
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-16 14:02:50
     * @update_author
     * @update_time
     * @version V1.0
     * @param
     * @return
    */
    Q_INVOKABLE static QString getLogPath();

private:
    /**
     * @Title: getLogTypeName方法
     * @Class: Logger
     * @Description: 获取日志类型名称
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:14:46
     * @update_author
     * @update_time
     * @version V1.0
     * @param type [LogType] 类型
     * @return [QString] 类型名称
    */
    static QString getLogTypeName(LogType type);

    /**
     * @Title: getDate方法
     * @Class: Logger
     * @Description: 获取当前日期
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:39:07
     * @update_author
     * @update_time
     * @version V1.0
     * @param
     * @return [QString] 当前日期
    */
    static QString getDate();

    /**
     * @Title: getLogMsg方法
     * @Class: Logger
     * @Description: 设置日志信息字符串
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:39:51
     * @update_author
     * @update_time
     * @version V1.0
     * @param
     * @return [QString] 日志信息字符串
    */
    static QString getLogMsg(LogType type, QString msg);

    /**
     * @Title: getFile方法
     * @Class: Logger
     * @Description: 获取当前日志文件
     * @author XueLong xuelongqy@foxmail.com
     * @date 2018-07-09 10:58:20
     * @update_author
     * @update_time
     * @version V1.0
     * @param [QString] 当前日志文件路径地址
     * @return
    */
    static QString getFile();
};

#endif // LOGGER_H
