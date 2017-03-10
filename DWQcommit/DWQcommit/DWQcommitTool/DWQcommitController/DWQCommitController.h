//
//  DWQCommitController.h
//  DWQCommitDemo
//
//  Created by 杜文全 on 16/5/10.
//  Copyright © 2016年 com.iOSDeveloper.duwenquan. All rights reserved.

#import <UIKit/UIKit.h>
#import "DWQCommitBaseController.h"
#import "DWQRatingView.h"
@interface DWQCommitController : DWQCommitBaseController
/**
 *  取消按钮+监听方法
 */
@property (weak, nonatomic) IBOutlet UIButton *cancelBtn;
- (IBAction)cancelClick:(UIButton *)sender;
/**
 *  title文字  默认分享新鲜事可在xib修改
 */
@property (weak, nonatomic) IBOutlet UILabel *titleLB;


//背景
@property(nonatomic,strong) UIView *noteTextBackgroudView;

//备注
@property(nonatomic,strong) UITextView *noteTextView;

//文字个数提示label
@property(nonatomic,strong) UILabel *textNumberLabel;

//文字说明
@property(nonatomic,strong) UILabel *explainLabel;

//五星好评
@property (nonatomic,strong) DWQRatingView *star;

//发布按钮
@property(nonatomic,strong) UIButton *submitBtn;




@end
