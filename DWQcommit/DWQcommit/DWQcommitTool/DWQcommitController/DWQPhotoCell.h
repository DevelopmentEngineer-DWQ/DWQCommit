//
//  DWQPhotoCell.h
//  DWQPublishDemo
//
//  Created by 杜文全 on 16/5/10.
//  Copyright © 2016年 com.iOSDeveloper.duwenquan. All rights reserved.

#import <UIKit/UIKit.h>

@interface DWQPhotoCell : UICollectionViewCell

@property (strong, nonatomic) IBOutlet UIImageView *profilePhoto;
@property (strong, nonatomic) IBOutlet UIButton *closeButton;

@property(nonatomic,strong) UIImageView *BigImgView;

/** 查看大图 */
- (void)setBigImgViewWithImage:(UIImage *)img;


@end
