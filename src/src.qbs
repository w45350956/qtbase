import qbs
import QtGlobalConfig
import QtGlobalPrivateConfig

Project {
    property stringList qtModuleNames: [
        "corelib",
        "gui",
        "network",
        "printsupport",
        "sql",
        "testlib",
        "widgets",
    ]
    qbsSearchPaths: qtModuleNames.map(function(name) {
        return qtbaseShadowDir + "/src/" + name + "/qbs";
    });
    references: qtModuleNames.concat([
        "3rdparty/3rdparty.qbs",
        // "android/android.qbs",
        "concurrent/concurrent.qbs",
        "dbus/dbus.qbs",
        "opengl",
        "openglextensions",
        "platformheaders/platformheaders.qbs",
        "platformsupport/platformsupport.qbs",
        "plugins/plugins.qbs",
        "tools/tools.qbs",
        "winmain/winmain.qbs",
        "xml/xml.qbs",
    ])
    Product {
        name: "Qt.global"
        Export {
            property var config: QtGlobalConfig
            property var privateConfig: QtGlobalPrivateConfig
        }
    }
}