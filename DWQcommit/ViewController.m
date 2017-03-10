//
//  ViewController.m
//  DWQcommit
//
//  Created by 杜文全 on 16/5/10.
//  Copyright © 2016年 com.iOSDeveloper.duwenquan. All rights reserved.
//

#import "ViewController.h"
#import "DWQcommitController.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}
- (IBAction)commit:(id)sender {
    
    DWQCommitController *publishVC = [[DWQCommitController alloc] init];
    [self presentViewController:publishVC animated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
