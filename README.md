# DWQCommit
电商平台确认收货后评价模块【包含五星好评】，照片选择，文字等
##DWQCommit由来

&emsp;&emsp;每一个电商平台，一套完整的电商系统，评价模块是不能缺少的，因为人们总是会通过买家的评论来判断商品质量的好坏。由于本人之前做电商比较多，所以为了方便以后使用，封装了DWQCommit框架。评价模块包含了两部分：
- 1、评论展示模块，类似微信的朋友圈

- 2、发布评价模块，类似了微博的发布模块

&emsp;&emsp;今天咱们要分享的就是发布评价模块，毕竟必须得先评价才能展示评价是吧。😀

##DWQCommit组成

![DWQCommit组成.png](http://upload-images.jianshu.io/upload_images/2231137-05cc074f5c573d9d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
DWQCommit包含4个文件夹：

- 1.DWQFivestarRating：五星好评封装控件
- 2.DWQcommitTool     ：评论封装主控件
- 3.Resources               ：图片资源文件夹
- 4.SDWebImage         ： 第三方库，加载图片用

##DWQFivestarRating的使用
首先将DWQFivestarRating文件夹拖入项目中调用方法有两种：
  *   链式调用（代码示例见下）
```javascript
   [DWQQRatingView init ]
   .frameChain（CGPointMake（60，100），50）
   .canTouchChain（YES）
   .needIntValueChain（YES）
   .scoreNumChain（@ 4）
   .scroreBlockChain（^（NSNumber * scoreNumber）{
   NSLog（@“ ％@ ”，scoreNumber）;
   }）。superViewChain（self.view）;
```
  *  普通调用 （代码示例见下）
```javascript
DWQRatingView *start2=[DWQRatingView initWithPoint:CGPointMake(Screenwidth/2-70, 230) withSize:30];
    
    [self.view addSubview:start2];
    start2.needIntValue=NO;   //是否整数显示，默认整数显示
    start2.canTouch=YES;//是否可以点击，默认为NO
    //start2.scoreNum=@4;//星星显示个数
    self.start2.normalColorChain([UIColor redColor]);
    start2.highlightColorChian([UIColor greenColor]);
    
    start2.scroreBlock=^(NSNumber *number){
    
        NSLog(@"返回的分数");
    
    };
```
##DWQCommit的使用
- 1.导入'DWQCommit'文件夹到项目中
 - 2.导入 ' #import "DWQCommitController.h" '
 - 3.在需要发布的按钮点击方法中
```objective-c
  DWQCommitController *publishVC = [[DWQCommitController alloc] init];
    [self presentViewController:publishVC animated:YES completion:nil];
}
```
 - 4.在DWQCommitController.m中submitToServer方法中编写上传服务器的代码
 - 5.由于需要访问相册和相机，需要在info.plist文件中配置权限
```objective-c
    <key>NSPhotoLibraryUsageDescription</key>
    <string>App需要您的同意,才能访问相册</string>
    <key>NSCameraUsageDescription</key>
    <string>App需要您的同意,才能访问相机</string>
```
##DWQCommit展示效果
- 1、初始界面
![初始界面.PNG](http://upload-images.jianshu.io/upload_images/2231137-b110ab8432268738.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/300)
- 2、添加图片，文字，选择星级分数后

![评论界面后.PNG](http://upload-images.jianshu.io/upload_images/2231137-d413fd7446f9df0a.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/300)
