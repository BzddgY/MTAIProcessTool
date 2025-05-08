//用来存一些常量
#ifndef CONST_H
#define CONST_H
#include <QObject>

enum ArraySensorType{
    LineArray = 1,//线阵
    RingArray = 2,//环阵，弧角限制为2pi
    SemiRingArray = 3,//半环阵，弧角限制为pi
    FiniteArcArray = 4,//有限弧度阵列，弧角可设置
};

enum ColorbarType{
    Gray = 1,//
    Hot= 2,//
    Parula = 3,//
    Jet = 4,//
    Thermal = 5,//
    Night = 6,//
    Cold = 7,//
    Candy = 8,//
};

enum VectorType{
    MatrixColumn = 1,//矩阵中的列向量
    MatrixRow = 2,//矩阵中的行向量
    Vector = 3,//向量
};

enum LabType{
    MITAI111Lab = 1,//实验室.dat文件导入，这里包含了MITAI111实验室的采集数据线序去耦合
    OtherLab = 2,//该类型在导入数据的时候直接导入为软件处理逻辑，及默认导入的数据符合NofSensors*Nt的矩阵
    //注意第一种类型只能导入.dat文件，第二种支持.txt,.csv等常见数据文件类型
};

enum RFDataLoadType{
    PathLoad = 1,//从路径根据所设置帧数导入射频数据，！！！批量处理只能用该选项，写代码过程中需要考虑到此！！！！！！
    AddressLoad = 2,//直接选择文件绝对路径导入，这种模式只能导入一个射频数据文件
};

enum FilterType{
    rectangleWindow = 6001,//矩形窗函数
    hammingWindow = 6002,//海明窗函数
    hanningWindow = 6003,//汉宁窗
    blackManWindow = 6004,//布莱克窗
    kaiserWindow = 6005,//凯瑟尔窗
};

//去卷积方式
enum DeConvolutionType{

};

//插值方式
enum InsertValueType{
    linear = 7001,//线性插值
    egi = 7002,//极值插值
};

//射线成像方式
enum RayImagingType{
    BP = 8001,//后向投影算法
    DAS = 8002,//延迟叠加算法
};


//线条样式，依次设置线条样式
enum LineStyle{
    ssNone = 9001,//直线
    ssCross = 9002,//×
    ssPlus = 9003,//+
    ssCircle = 9004,//空心圆
    ssDisc = 9005,//实心圆
    ssSquare = 9006,//空心方块
    ssStar = 9007,//*
};

const QVector<QString> WordType{"Adobe 宋体 Std L",
                              "Adobe 黑体 Std R",
                              "Arial",
                              "Arial Black",
                              "Arial Narrow",
                              "Bahnschrift",
                              "Bahnschrift Condensed",
                              "Bahnschrift Light",
                              "Bahnschrift Light Condensed",
                              "Bahnschrift Light SemiCondensed",
                              "Bahnschrift SemiBold",
                              "Bahnschrift SemiBold Condensed",
                              "Bahnschrift SemiBold SemiConden",
                              "Bahnschrift SemiCondensed",
                              "Bahnschrift SemiLight",
                              "Bahnschrift SemiLight Condensed",
                              "Bahnschrift SemiLight SemiConde",
                              "Book Antiqua",
                              "Bookman Old Style",
                              "Bookshelf Symbol 7",
                              "Bradley Hand ITC",
                              "Calibri",
                              "Calibri Light",
                              "Cambria",
                              "Cambria Math",
                              "Candara",
                              "Candara Light",
                              "Cascadia Code",
                              "Cascadia Code ExtraLight",
                              "Cascadia Code Light",
                              "Cascadia Code SemiBold",
                              "Cascadia Code SemiLight",
                              "Cascadia Mono",
                              "Cascadia Mono ExtraLight",
                              "Cascadia Mono Light",
                              "Cascadia Mono SemiBold",
                              "Cascadia Mono SemiLight",
                              "Century",
                              "Century Gothic",
                              "Comic Sans MS",
                              "Consolas",
                              "Constantia",
                              "Corbel",
                              "Corbel Light",
                              "Courier",
                              "Courier New",
                              "DIN Next LT Pro",
                              "DIN Next LT Pro Light",
                              "DIN Next LT Pro Medium",
                              "Dubai",
                              "Dubai Light",
                              "Dubai Medium",
                              "Ebrima",
                              "Euclid",
                              "Euclid Extra",
                              "Euclid Fraktur",
                              "Euclid Math One",
                              "Euclid Math Two",
                              "Euclid Symbol",
                              "Fences",
                              "Fixedsys",
                              "Franklin Gothic Medium",
                              "Freestyle Script",
                              "French Script MT",
                              "Gabriola",
                              "Gadugi",
                              "Garamond",
                              "Georgia",
                              "HarmonyOS Sans SC",
                              "HarmonyOS Sans SC Medium",
                              "HONOR Sans",
                              "HONOR Sans Arabic UI L",
                              "HONOR Sans Arabic UI M",
                              "HONOR Sans Arabic UI R",
                              "HONOR Sans CN",
                              "HONOR Sans CN Light",
                              "HONOR Sans CN Medium",
                              "HONOR Sans Design",
                              "HONOR Sans Design Demibold",
                              "HONOR Sans Design Demibold DISP",
                              "HONOR Sans Design DISP",
                              "HONOR Sans Design ExtraBold",
                              "HONOR Sans Design ExtraBold DIS",
                              "HONOR Sans Design ExtraLight",
                              "HONOR Sans Design ExtraLight DI",
                              "HONOR Sans Design Heavy",
                              "HONOR Sans Design Heavy DISP",
                              "HONOR Sans Design Light",
                              "HONOR Sans Design Light DISP",
                              "HONOR Sans Design Medium",
                              "HONOR Sans Design Medium DISP",
                              "HONOR Sans Design Thin",
                              "HONOR Sans Design Thin DISP",
                              "HONOR Sans Display GBK",
                              "HONOR Sans Display GBK DemiBold",
                              "HONOR Sans Display GBK ExtraBol",
                              "HONOR Sans Display GBK ExtraLig",
                              "HONOR Sans Display GBK Heavy",
                              "HONOR Sans Display GBK Light",
                              "HONOR Sans Display GBK Medium",
                              "HONOR Sans Display GBK Thin",
                              "HONOR Sans Light",
                              "HONOR Sans Medium",
                              "HONOR Sans Text GBK",
                              "HONOR Sans Text GBK DemiBold",
                              "HONOR Sans Text GBK ExtraBold",
                              "HONOR Sans Text GBK ExtraLight",
                              "HONOR Sans Text GBK Heavy",
                              "HONOR Sans Text GBK Light",
                              "HONOR Sans Text GBK Medium",
                              "HONOR Sans Text GBK Thin",
                              "Impact",
                              "Ink Free",
                              "Javanese Text",
                              "Juice ITC",
                              "Kristen ITC",
                              "Leelawadee UI",
                              "Leelawadee UI Semilight",
                              "Lucida Console",
                              "Lucida Handwriting",
                              "Lucida Sans Unicode",
                              "Malgun Gothic",
                              "Malgun Gothic Semilight",
                              "Marlett",
                              "Microsoft Himalaya",
                              "Microsoft JhengHei",
                              "Microsoft JhengHei Light",
                              "Microsoft JhengHei UI",
                              "Microsoft JhengHei UI Light",
                              "Microsoft New Tai Lue",
                              "Microsoft PhagsPa",
                              "Microsoft Sans Serif",
                              "Microsoft Tai Le",
                              "Microsoft YaHei UI",
                              "Microsoft YaHei UI Light",
                              "Microsoft Yi Baiti",
                              "MingLiU-ExtB",
                              "MingLiU_HKSCS-ExtB",
                              "MingLiU_MSCS-ExtB",
                              "Mistral",
                              "Modern",
                              "Mongolian Baiti",
                              "Monotype Corsiva",
                              "MS Gothic",
                              "MS PGothic",
                              "MS Reference Sans Serif",
                              "MS Reference Specialty",
                              "MS Sans Serif",
                              "MS Serif",
                              "MS UI Gothic",
                              "MT Extra",
                              "MT Extra Tiger",
                              "MV Boli",
                              "Myanmar Text",
                              "Nirmala Text",
                              "Nirmala Text Semilight",
                              "Nirmala UI",
                              "Nirmala UI Semilight",
                              "NumberOnly",
                              "Origin",
                              "Palatino Linotype",
                              "Papyrus",
                              "PMingLiU-ExtB",
                              "Pristina",
                              "Roman",
                              "Sans Serif Collection",
                              "Script",
                              "Segoe Fluent Icons",
                              "Segoe MDL2 Assets",
                              "Segoe Print",
                              "Segoe Script",
                              "Segoe UI",
                              "Segoe UI Black",
                              "Segoe UI Emoji",
                              "Segoe UI Historic",
                              "Segoe UI Light",
                              "Segoe UI Semibold",
                              "Segoe UI Semilight",
                              "Segoe UI Symbol",
                              "Segoe UI Variable Display",
                              "Segoe UI Variable Display Light",
                              "Segoe UI Variable Display Semib",
                              "Segoe UI Variable Display Semil",
                              "Segoe UI Variable Small",
                              "Segoe UI Variable Small Light",
                              "Segoe UI Variable Small Semibol",
                              "Segoe UI Variable Small Semilig",
                              "Segoe UI Variable Text",
                              "Segoe UI Variable Text Light",
                              "Segoe UI Variable Text Semibold",
                              "Segoe UI Variable Text Semiligh",
                              "SimSun-ExtB",
                              "SimSun-ExtG",
                              "Sitka Banner",
                              "Sitka Banner Semibold",
                              "Sitka Display",
                              "Sitka Display Semibold",
                              "Sitka Heading",
                              "Sitka Heading Semibold",
                              "Sitka Small",
                              "Sitka Small Semibold",
                              "Sitka Subheading",
                              "Sitka Subheading Semibold",
                              "Sitka Text",
                              "Sitka Text Semibold",
                              "Small Fonts",
                              "SpaceClaim ASME CB",
                              "SpaceClaim ISO CB",
                              "Sylfaen",
                              "Symbol",
                              "Symbol Tiger",
                              "Symbol Tiger Expert",
                              "System",
                              "Tahoma",
                              "Tempus Sans ITC",
                              "Terminal",
                              "Tiger",
                              "Tiger Expert",
                              "Times New Roman",
                              "Trebuchet MS",
                              "Verdana",
                              "WarSym_Equip_ENY",
                              "WarSym_Equip_FR",
                              "WarSym_Equip_NEU",
                              "WarSym_Equip_UNK",
                              "WarSym_Gnd_Cbt_ENY",
                              "WarSym_Gnd_Cbt_FR",
                              "WarSym_Gnd_Cbt_NEU",
                              "WarSym_Gnd_Cbt_UNK",
                              "WarSym_Gnd_Cs_ENY",
                              "WarSym_Gnd_Cs_FR",
                              "WarSym_Gnd_Cs_NEU",
                              "WarSym_Gnd_Cs_UNK",
                              "WarSym_MOOTW_ENY",
                              "WarSym_MOOTW_FR",
                              "WarSym_MOOTW_NEU",
                              "WarSym_MOOTW_UNK",
                              "WarSym_SAS_ENY",
                              "WarSym_SAS_FR",
                              "WarSym_SAS_NEU",
                              "WarSym_SAS_UNK",
                              "warsym_tac_graf_points mil2525",
                              "Webdings",
                              "Wingdings",
                              "Wingdings 2",
                              "Wingdings 3",
                              "Yu Gothic",
                              "Yu Gothic Light",
                              "Yu Gothic Medium",
                              "Yu Gothic UI",
                              "Yu Gothic UI Light",
                              "Yu Gothic UI Semibold",
                              "Yu Gothic UI Semilight",
                              "仿宋",
                              "华文中宋",
                              "华文仿宋",
                              "华文宋体",
                              "华文彩云",
                              "华文新魏",
                              "华文楷体",
                              "华文琥珀",
                              "华文细黑",
                              "华文行楷",
                              "华文隶书",
                              "宋体",
                              "幼圆",
                              "微软雅黑",
                              "微软雅黑 Light",
                              "新宋体",
                              "方正姚体",
                              "方正粗黑宋简体",
                              "方正舒体",
                              "楷体",
                              "爱奇艺黑体",
                              "爱奇艺黑体 Medium",
                              "等线",
                              "等线 Light",
                              "长仿宋体",
                              "隶书",
                              "黑体"};

enum NonNegativeImagingType{
    Amplitude = 10001,//幅度值
    Energy1 = 10002,//单点平方能量值
    Energy2 = 10003,//窗内能量总值
    Peak_Peak = 10004,//窗内峰峰值
};

//非负成像方式

const int MAINWINDOW_WIDTH = 900;
const int MAINWINDOW_HEIGHT = 800;

//默认上下左右空出15mm！！！！
const int EXPAND_WIDTH = 15;//TR计算或绘制传感器时将传感器包含进去的最小扩宽的宽度[mm]
const float DEFAULT_DELTA_X = 2;//默认方形网格大小[mm]

const qint64 MY_TADATABOX_MAX_MEMORY = 1024 * 1024 * 1024; // TADataBox 最大内存限制1GB

const int N_SCATTER_DOTS = 100;//散点图曲线共画多少点

const int PROGRESS_WIDTH = 300;//进度条窗口宽度

#endif // CONST_H
