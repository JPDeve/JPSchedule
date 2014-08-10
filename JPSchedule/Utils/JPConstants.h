//
//  Constans.h
//  8thManageNative
//
//  Created by podywu on 14-1-9.
//  Copyright (c) 2014年 WisageTech. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  判断iPhone 5 宏
 *	使用：if (iPhone5)
 */
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

/*
 *  判断iOS 7 宏
 *	使用：
 if (SYSTEM_VERSION_LESS_THAN(@"5.0")) {
 // code here
 }
 
 if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")) {
 // code here
 }
 */


// 判断iOS版本
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


//多语言
#define localString(local) NSLocalizedString(local, nil)

// 判断对象是否为Null，如果不是就赋值
#define SET_IF_NOT_NULL(TARGET, VAL) if(VAL != [NSNull null]) { TARGET = VAL; }

// 判断对象是否为nil，如果不是就赋值
#define SET_IF_NOT_NIL(TARGET, VAL) if(VAL != nil) { TARGET = VAL; }

// 判断对象是否为Null
#define IS_NULL(TARGET)  ([TARGET isEqual:[NSNull null]])


//是否是ios7.0系统
#define IOS7 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0 ? YES:NO) //IOS7.0


// appDelegate
#define appDelegate	((MPAppDelegate *)[[UIApplication sharedApplication] delegate])

//判断字符是否为中文
#define IS_CH_SYMBOL(chr) ((int)(chr)>127)

#define ios7_y 20

#define OPENUDID [OpenUDID value]

#define NavigationBar_HEIGHT 44

#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)
#define SAFE_RELEASE(x) [x release];x=nil
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion ([[UIDevice currentDevice] systemVersion])
//#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

#define BACKGROUND_COLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]



//use dlog to print while in debug model
#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

//use stringmake for NSString
#define StringMake(fmt, ...) [NSString stringWithFormat:(fmt), ##__VA_ARGS__]




#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif


//ARC
#if __has_feature(objc_arc)
//compiling with ARC
#else
// compiling without ARC
#endif


//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)


#define USER_DEFAULT [NSUserDefaults standardUserDefaults]
#define ImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer]]



#pragma mark - common functions
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }


#pragma mark - degrees/radian functions
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)

#pragma mark - color functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define ITTDEBUG
#define ITTLOGLEVEL_INFO     10
#define ITTLOGLEVEL_WARNING  3
#define ITTLOGLEVEL_ERROR    1

#ifndef ITTMAXLOGLEVEL

#ifdef DEBUG
#define ITTMAXLOGLEVEL ITTLOGLEVEL_INFO
#else
#define ITTMAXLOGLEVEL ITTLOGLEVEL_ERROR
#endif

#endif

// The general purpose logger. This ignores logging levels.
#ifdef ITTDEBUG
#define ITTDPRINT(xx, ...)  NSLog(@"%s(%d): " xx, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define ITTDPRINT(xx, ...)  ((void)0)
#endif

// Prints the current method's name.
#define ITTDPRINTMETHODNAME() ITTDPRINT(@"%s", __PRETTY_FUNCTION__)

// Log-level based logging macros.
#if ITTLOGLEVEL_ERROR <= ITTMAXLOGLEVEL
#define ITTDERROR(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDERROR(xx, ...)  ((void)0)
#endif

#if ITTLOGLEVEL_WARNING <= ITTMAXLOGLEVEL
#define ITTDWARNING(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDWARNING(xx, ...)  ((void)0)
#endif

#if ITTLOGLEVEL_INFO <= ITTMAXLOGLEVEL
#define ITTDINFO(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)
#else
#define ITTDINFO(xx, ...)  ((void)0)
#endif

#ifdef ITTDEBUG
#define ITTDCONDITIONLOG(condition, xx, ...) { if ((condition)) { \
ITTDPRINT(xx, ##__VA_ARGS__); \
} \
} ((void)0)
#else
#define ITTDCONDITIONLOG(condition, xx, ...) ((void)0)
#endif

#define ITTAssert(condition, ...)                                       \
do {                                                                      \
if (!(condition)) {                                                      \
[[NSAssertionHandler currentHandler]                                  \
handleFailureInFunction:[NSString stringWithUTF8String:__PRETTY_FUNCTION__] \
file:[NSString stringWithUTF8String:__FILE__]  \
lineNumber:__LINE__                                  \
description:__VA_ARGS__];                             \
}                                                                       \
} while(0)



#define _po(o) DLOG(@"%@", (o))
#define _pn(o) DLOG(@"%d", (o))
#define _pf(o) DLOG(@"%f", (o))
#define _ps(o) DLOG(@"CGSize: {%.0f, %.0f}", (o).width, (o).height)
#define _pr(o) DLOG(@"NSRect: {{%.0f, %.0f}, {%.0f, %.0f}}", (o).origin.x, (o).origin.x, (o).size.width, (o).size.height)

#define DOBJ(obj)  DLOG(@"%s: %@", #obj, [(obj) description])

#define MARK    NSLog(@"\nMARK: %s, %d", __PRETTY_FUNCTION__, __LINE__)

#ifdef DEBUG
//Debug模式
//...


#else
//发布模式
//...

//屏蔽NSLog
#define NSLog(...) {};

#endif


//------------------------------------Simulator/Device
//区分模拟器和真机
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

//------------------------------------ARC/no RAC
//ARC
#if __has_feature(objc_arc)
//compiling with ARC
#else
// compiling without ARC
#endif

//Block
typedef void(^VoidBlock)();
typedef BOOL(^BoolBlock)();
typedef int (^IntBlock) ();
typedef id  (^IDBlock)  ();

typedef void(^VoidBlock_int)(int);
typedef BOOL(^BoolBlock_int)(int);
typedef int (^IntBlock_int) (int);
typedef id  (^IDBlock_int)  (int);

typedef void(^VoidBlock_string)(NSString*);
typedef BOOL(^BoolBlock_string)(NSString*);
typedef int (^IntBlock_string) (NSString*);
typedef id  (^IDBlock_string)  (NSString*);

typedef void(^VoidBlock_id)(id);
typedef BOOL(^BoolBlock_id)(id);
typedef int (^IntBlock_id) (id);
typedef id  (^IDBlock_id)  (id);

//Font
#define FontMicrosoftSize(fontSize) [UIFont fontWithName:@"MicrosoftYaHei" size:fontSize];


//System
#define PasteString(string)   [[UIPasteboard generalPasteboard] setString:string];
#define PasteImage(image)     [[UIPasteboard generalPasteboard] setImage:image];


//Image
//可拉伸的图片

#define ResizableImage(name,top,left,bottom,right) [[UIImage imageNamed:name] resizableImageWithCapInsets:UIEdgeInsetsMake(top,left,bottom,right)]
#define ResizableImageWithMode(name,top,left,bottom,right,mode) [[UIImage imageNamed:name] resizableImageWithCapInsets:UIEdgeInsetsMake(top,left,bottom,right) resizingMode:mode]

#define ResizableImageWithModeStretech(name,top,left,bottom,right) [[UIImage imageNamed:name] resizableImageWithCapInsets:UIEdgeInsetsMake(top,left,bottom,right) resizingMode:UIImageResizingModeStretch]

//file
//读取文件的文本内容,默认编码为UTF-8
#define FileString(name,ext)            [[NSString alloc] initWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(name) ofType:(ext)] encoding:NSUTF8StringEncoding error:nil]
#define FileDictionary(name,ext)        [[NSDictionary alloc] initWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(name) ofType:(ext)]]
#define FileArray(name,ext)             [[NSArray alloc] initWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(name) ofType:(ext)]]

//数学
#define PI 3.14159

//输出frame(frame是结构体，没法%@)
#define LOGFRAME(f) NSLog(@"\nx:%f\ny:%f\nwidth:%f\nheight:%f\n",f.origin.x,f.origin.y,f.size.width,f.size.height)
#define LOGBOOL(b)  NSLog(@"%@",b?@"YES":@"NO");
//弹出信息
#define ALERT(msg) [[[UIAlertView alloc] initWithTitle:nil message:msg delegate:nil cancelButtonTitle:localString(@"ok") otherButtonTitles:nil] show]


//App
#define kApp ((AppDelegate *)[UIApplication sharedApplication].delegate)
#define kNav ((AppDelegate *)[UIApplication sharedApplication].delegate.navigationController)


//color
#define RGB(r, g, b)             [UIColor colorWithRed:((r) / 255.0) green:((g) / 255.0) blue:((b) / 255.0) alpha:1.0]
#define RGBAlpha(r, g, b, a)     [UIColor colorWithRed:((r) / 255.0) green:((g) / 255.0) blue:((b) / 255.0) alpha:(a)]

#define HexRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define HexRGBAlpha(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]

#define Common_Bg_Color HexRGB(0x08c2b7)

//转换
#define I2S(number) [NSString stringWithFormat:@"%d",number]
#define F2S(number) [NSString stringWithFormat:@"%f",number]
#define DATE(stamp) [NSDate dateWithTimeIntervalSince1970:[stamp intValue]];



//设备屏幕尺寸
#define kScreen_Height   ([UIScreen mainScreen].bounds.size.height)
#define kScreen_Width    ([UIScreen mainScreen].bounds.size.width)
#define kScreen_Frame    (CGRectMake(0, 0 ,kScreen_Width,kScreen_Height))
#define kScreen_CenterX  kScreen_Width/2
#define kScreen_CenterY  kScreen_Height/2


//应用尺寸(不包括状态栏,通话时状态栏高度不是20，所以需要知道具体尺寸)
#define kContent_Height   ([UIScreen mainScreen].applicationFrame.size.height)
#define kContent_Width    ([UIScreen mainScreen].applicationFrame.size.width)
#define kContent_Frame    (CGRectMake(0, 0 ,kContent_Width,kContent_Height))
#define kContent_CenterX  kContent_Width/2
#define kContent_CenterY  kContent_Height/2



/*
 类似九宫格的九个点
 
 p1 --- p2 --- p3
 |      |      |
 p4 --- p5 --- p6
 |      |      |
 p7 --- p8 --- p9
 
 */
#define kP1 CGPointMake(0                 ,0)
#define kP2 CGPointMake(kContent_Width/2  ,0)
#define kP3 CGPointMake(kContent_Width    ,0)
#define kP4 CGPointMake(0                 ,kContent_Height/2)
#define kP5 CGPointMake(kContent_Width/2  ,kContent_Height/2)
#define kP6 CGPointMake(kContent_Width    ,kContent_Height/2)
#define kP7 CGPointMake(0                 ,kContent_Height)
#define kP8 CGPointMake(kContent_Width/2  ,kContent_Height)
#define kP9 CGPointMake(kContent_Width    ,kContent_Height)

//*********************************************


//GCD
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)


//Device
#define isIOS4 ([[[UIDevice currentDevice] systemVersion] intValue]==4)
#define isIOS5 ([[[UIDevice currentDevice] systemVersion] intValue]==5)
#define isIOS6 ([[[UIDevice currentDevice] systemVersion] intValue]==6)
#define isAfterIOS4 ([[[UIDevice currentDevice] systemVersion] intValue]>4)
#define isAfterIOS5 ([[[UIDevice currentDevice] systemVersion] intValue]>5)
#define isAfterIOS6 ([[[UIDevice currentDevice] systemVersion] intValue]>6)

#define iOS ([[[UIDevice currentDevice] systemVersion] floatValue])

#define isRetina ([[UIScreen mainScreen] scale]==2)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//拨打电话
#define canTel                 ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"tel:"]])
#define tel(phoneNumber)       ([[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"tel://%@",phoneNumber]]])
#define telprompt(phoneNumber) ([[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"telprompt:%@",phoneNumber]]])

//打开URL
#define canOpenURL(appScheme) ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:appScheme]])
#define openURL(appScheme) ([[UIApplication sharedApplication] openURL:[NSURL URLWithString:appScheme]])


// App相关
//#define appName  ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"])
#define appVersion  ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])
#define appBuild  ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])

// XMPP
#define XMPPService (IMXMPPService *)[IMXMPPService sharedInstance]

// iPad menu width
#define kMenuWidth 200

// ipad菜单收起时的宽度
#define kLeftInset 80

// ipad菜单展开时的宽度
#define kLargeLeftInset kMenuWidth

#define IPAD_WIDTH 1024
#define IPAD_HEIGHT 768

// ipad中间视图的宽度
#define CENTER_VIEW_WIDTH 375
// ipad右侧视图的宽度，569
#define RIGHT_VIEW_WIDTH (IPAD_WIDTH - kLeftInset - CENTER_VIEW_WIDTH)

// iPad全屏视图的frame
#define FULL_SCREEN_VIEW_FRAME CGRectMake(0, 0, IPAD_WIDTH, IPAD_HEIGHT)
// ipad中间视图的frame
#define CENTER_VIEW_FRAME CGRectMake(0, 0, CENTER_VIEW_WIDTH, IPAD_HEIGHT)
// ipad右侧视图的frame
#define RIGHT_VIEW_FRAME CGRectMake(0, 0, RIGHT_VIEW_WIDTH, IPAD_HEIGHT)

#define IS_IPHONE4_SCREEN ([[UIScreen mainScreen] bounds].size.height == 480)

// Constans

//SSKeychain 框架使用
#define KEY_SERVICE @"zdnst"

#define KEY_ACCOUNT_PW @"zdnst_pw"

#define KEY_ACCOUNT_UN @"zdnst_un"

#define KEY_ACCOUNT_UID @"zdnst_uid"

// 是否开启Demo状态
#define isDemo NO

// ****** 活动 ******
// 活动封面大小
#ifndef PAD
#define ACTIVITY_COVER_SIZE CGSizeMake(320, 320.0/2)
#else
#define ACTIVITY_COVER_SIZE CGSizeMake(375, 375.0/2)
#endif

// 隐藏PAD版本状态栏
#ifndef PAD
#define hidStatusBar ([[UIApplication sharedApplication] setStatusBarHidden:NO])
#else
#define hidStatusBar ([[UIApplication sharedApplication] setStatusBarHidden:YES])
#endif




// 空值转换为空字符串
#define NULLSTRING(OBJ) ((OBJ!=nil&&[OBJ length]>0)?OBJ:@"")

#define ISADD      @"isAdd"//是否是添加联系人的建

//异常日志文件名称
#define EXCEPTION_FILE @"exception_ios.log"

//是否为调试
#define isDebug NO

@interface MPConstants : NSObject




@end
