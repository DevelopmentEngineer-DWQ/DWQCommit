//
//  DWQRatingView.h
//  Five-star-rating
//
//  Created by 杜文全 on 15/2/13.
//  Copyright © 2015年 com.sdsj.duwenquan. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void(^DWQScoreBlock)(NSNumber *scoreNumber);

@class DWQRatingView;

typedef DWQRatingView *(^DWQFrameChain)(CGPoint point, float size);
typedef DWQRatingView *(^DWQNeedIntValueChain)(BOOL needIntValue);
typedef DWQRatingView *(^DWQCanTouchChain)(BOOL canTouch);
typedef DWQRatingView *(^DWQScroreBlockChain)(DWQScoreBlock scroreBlock);
typedef DWQRatingView *(^DWQScoreNumChain)(NSNumber *scoreNum);
typedef DWQRatingView * (^DWQSuperViewChain)(UIView *superView);
typedef DWQRatingView * (^DWQColorChain)          (UIColor *color);
@interface DWQRatingView : UIView
#pragma mark -- 链式调用
/**
 *  链式调用
 *
 *  @return GQRatingView
 */
+ (instancetype)init;

/**
 *  设置point和size   传值 : frameChain(CGPoint,float)
 */
@property (nonatomic, copy, readonly) DWQFrameChain          frameChain;

/**
 *  分数是否显示为整数 如果为yes星星都是整个整个显示   needIntValueChain(BOOL)
 */
@property (nonatomic, copy, readonly) DWQNeedIntValueChain   needIntValueChain;

/**
 *  默认为NO  星星是否可以点击   canTouchChain(BOOL)
 */
@property (nonatomic, copy, readonly) DWQCanTouchChain       canTouchChain;

/**
 *  如果touch为YES 这个也可以一起实现  scroreBlockChain(GQScoreBlock)
 */
@property (nonatomic, copy, readonly) DWQScroreBlockChain    scroreBlockChain;

/**
 *  初始分数    默认满分为5分 0 - 5   scoreNumChain(NSNumber *)
 */
@property (nonatomic, copy, readonly) DWQScoreNumChain       scoreNumChain;

/**
 底色  默认为[UIColor grayColor]
 */
@property (nonatomic, copy, readonly) DWQColorChain          normalColorChain;

/**
 高亮色 默认为[UIColor yellowColor]
 */
@property (nonatomic, copy, readonly) DWQColorChain          highlightColorChian;

/**
 *  显示在哪个view上面   superViewChain(UIView *)
 */
@property (nonatomic, copy, readonly) DWQSuperViewChain      superViewChain;

#pragma mark -- 方法调用

/**
 *  initMethod
 *
 *  @param point x y坐标
 *  @param size  单个星星大小
 *
 *  @return GQRatingView
 */
+ (instancetype)initWithPoint:(CGPoint)point withSize:(float)size;

/**
 *  分数是否显示为整数 如果为yes星星都是整个整个显示
 */
@property (nonatomic, assign) BOOL needIntValue;

/**
 *  默认为NO  星星是否可以点击
 */
@property (nonatomic, assign) BOOL canTouch;

/**
 *  如果touch为YES 这个也可以一起实现
 */
@property (nonatomic, copy) DWQScoreBlock scroreBlock;

/**
 *  初始分数    默认满分为5分 0 - 5
 */
@property (nonatomic,strong) NSNumber *scoreNum;

/**
 设置底色
 */
@property (nonatomic, strong) UIColor *normalColor;

/**
 设置高亮颜色
 */
@property (nonatomic, strong) UIColor *highlightColor;
@end
