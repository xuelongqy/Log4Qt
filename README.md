# Log4Qt

> A simple logger for Qt(一个简单的Qt日志库)

#### How to use(这样使用)

1、Import Logger(导入Logger)

```javascript
Use Logger.pro[Recommended](使用Logger.pro,推荐)
SUBDIRS += Logger

Or use Logger.pri(或则使用Logger.pri)
include(Logger/Logger.pri)
```

2、Config Logger(配置Logger)

```C++
Config model(配置结构)
struct LogConfig
{
    // Log save path, defaults to./log(日志路径,默认当前目录的log文件夹内,配置输出文件后生效)
    QString path = "./log";
    // Date format(日期格式)
    QString dataType = "yyyy-MM-dd hh:mm:ss:zzz";
    // Log pattern(日志输出规则)
    QString pattern = "%D %T %M";
    // Console config(控制台配置)
    bool outConsole = true;
    // Higher than this level output(高于这个级别输出)
    LogType consoleType = LogType::DEBUG;
    // File config(文件配置)
    bool outFile = true;
    // Higher than this level output(高于这个级别输出)
    LogType fileType = LogType::DEBUG;
};
```
```C++
Set config(修改配置)
Logger::logConfig.path = QDir::homePath() + "/" + "Log4Qt" + "/" + "log";
Logger::logConfig.fileType = LogType::WARNING;
...
```
```C++
Import to Qml(注入Qml)
//Here you can customize.(你可以自定义,这里仅仅是举例)
qmlRegisterType<Logger>("com.knoyo.logger", 1, 0, "Logger");
```

3、Use Logger(使用Logger)

```C++
Use in C++(在C++中使用)
#include <logger.h>
Logger::d("...");
Logger::i("...");
Logger::w("...");
Logger::e("...");
```
```javascript
Use in Qml(在Qml中使用)
import com.knoyo.logger 1.0
Logger {
    id: logger
}
logger.d("...")
logger.i("...")
logger.w("...")
logger.e("...")
```

#### You can refer to Demo, which is really very simple.(你可以参考Demo使用，这真的很简单)
