//
//  DWQPhotoCell.m
//  DWQPublishDemo
//
//  Created by 杜文全 on 16/5/10.
//  Copyright © 2016年 com.iOSDeveloper.duwenquan. All rights reserved.

#import "DWQPhotoCell.h"

@implementation DWQPhotoCell

/** 查看大图 */
- (void)setBigImgViewWithImage:(UIImage *)img{
    if (_BigImgView) {
        //如果大图正在显示，还原小图
        _BigImgView.frame = _profilePhoto.frame;
        _BigImgView.image = img;
    }else{
        _BigImgView = [[UIImageView alloc] initWithImage:img];
        _BigImgView.frame = _profilePhoto.frame;
        [self insertSubview:_BigImgView atIndex:0];
    }
    _BigImgView.contentMode = UIViewContentModeScaleToFill;
}

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

@end
