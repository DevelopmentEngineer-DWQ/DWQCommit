//
//  DWQStarView.m
//  Five-star-rating
//
//  Created by 杜文全 on 15/2/13.
//  Copyright © 2015年 com.sdsj.duwenquan. All rights reserved.
//

#import "DWQStarView.h"
static const float defaultAngle = - M_PI_2;//默认开始偏移角度

static const float MPI_2 = M_PI * 2;

static const float smallRadiuPercent = 0.4; //内部半径比例   值越小，星星越瘦

#define bgStrokeColor [UIColor clearColor]  //描边颜色

extern UIImage * getImageFromView(UIView *orgView)
{
    UIGraphicsBeginImageContext(orgView.bounds.size);
    [orgView.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

@interface DWQStarView() {
    UIColor *bgStarColor;   //填充颜色
}

@end
@implementation DWQStarView

+ (UIImage *)getStarWithRadius:(float)radius withFillColor:(UIColor *)fillColor
{
    DWQStarView *view = [[self alloc] initWithFrame:CGRectMake(0, 0, radius*4, radius*4) withFillColor:fillColor];
    [view setNeedsDisplay];
    return getImageFromView(view);
}

- (instancetype)initWithFrame:(CGRect)frame withFillColor:(UIColor *)fillColor
{
    self = [super initWithFrame:frame];
    if (self) {
        bgStarColor = fillColor;
        self.backgroundColor = [UIColor clearColor];
    }
    return self;
}

- (void)drawRect:(CGRect)rect
{
    CGFloat centerPoint = rect.size.width / 2;
    
    CGFloat radius = rect.size.width/2;
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGMutablePathRef startPath = CGPathCreateMutable();
    
    NSMutableArray *angles = [NSMutableArray array];
    
    for (int i = 0; i < 10; i++) {
        [angles addObject:@((defaultAngle +i/10.0 * MPI_2))];
    }
    
    for (int i = 0; i < angles.count; i++) {
        
        CGFloat angle = [[angles objectAtIndex:i] doubleValue];
        
        CGFloat r = i % 2 == 0 ? radius : centerPoint*smallRadiuPercent;
        
        CGFloat x = centerPoint + r * cos(angle);
        
        CGFloat y = centerPoint + r * sin(angle);
        
        if (i == 0) {
            CGPathMoveToPoint(startPath, NULL, x, y);
        } else {
            CGPathAddLineToPoint(startPath, NULL, x, y);
        }
    }
    
    CGPathCloseSubpath(startPath);
    
    CGContextAddPath(context, startPath);
    
    CGContextSetFillColorWithColor(context, bgStarColor.CGColor);
    
    CGContextSetStrokeColorWithColor(context, bgStrokeColor.CGColor);
    
    CGContextStrokePath(context);
    
    CGRect range = self.frame;
    
    CGContextAddPath(context, startPath);
    
    CGContextClip(context);
    
    CGContextFillRect(context, range);
    
    CFRelease(startPath);
}


@end
