//
//  MPNetwork.m
//  maps
//
//  Created by Sencho Kong on 14-5-28.
//  Copyright (c) 2014年 zdnst. All rights reserved.
//

#import "JPNetwork.h"
#import "SVProgressHUD.h"


//外网请求URL常量
NSString *const MPBaseURLString = @"这里是请求url";

@interface MPNetwork (){
    
    
}

@end

@implementation MPNetwork

/*
 * 重写 manager 方法设置URL常量
 */

+ (instancetype)manager {
    
    return [[self alloc] initWithBaseURL:[NSURL URLWithString:MPBaseURLString]];
}




- (AFHTTPRequestOperation *)requestWithMethod:(NSString*)method
                                    URLString:(NSString *)URLString
                                   parameters:(id)parameters
                                      success:(successBlock)successBlock
                                      failure:(failureBlock)failureBlock
{
    //先判断网络是否存在，存在则请求
    BOOL isNetWorkExist=[MPNetwork isNetworkExist];
    if (!isNetWorkExist) {
        
        DTAlertView *alertView =[DTAlertView alertViewWithTitle:@"当前网络不可用" message:@"无法连接到服务器，请检查你的网络设置" delegate:nil cancelButtonTitle:@"确定"  positiveButtonTitle:nil];
        
        
        [alertView show];
        
        [SVProgressHUD dismiss];
        
        return nil;
    }
    
    
    NSMutableURLRequest *request = [self.requestSerializer requestWithMethod:method URLString:[[NSURL URLWithString:URLString relativeToURL:self.baseURL] absoluteString] parameters:parameters error:nil];
    AFHTTPRequestOperation *operation = [self HTTPRequestOperationWithRequest:request success:nil failure:nil];
    [self operation:operation addCompletionBlock:successBlock errorBlock:failureBlock];
    [self.operationQueue addOperation:operation];
    return operation;
}



/**
 *  二次封装返回block
 *  接口返回定义
 *  code    :成功标识 1成功 0失败
 *  message :返回提示语
 *  data    :返回数据体
 *
 *  @param op           AFHTTPRequestOperation
 *  @param successBlock successBlock description
 *  @param failureBlock failureBlock description
 */
- (void)operation:(AFHTTPRequestOperation *)op addCompletionBlock:(successBlock)successBlock
       errorBlock:(failureBlock)failureBlock  {
    
    [op setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject) {
        
        
        [SVProgressHUD dismiss];
        DLog(@"%@", responseObject);
        
        NSString* retmsg=responseObject[@"message"];
        if (!retmsg || [retmsg isKindOfClass:[NSNull class]]) {
            retmsg=@"未知的错误！";
        }
        
        int code = [responseObject[@"code"] intValue];
        //1成功，其它失败
        if (code == 1 && responseObject) {
            DLog(@"%@", retmsg);
            successBlock(operation,responseObject);
            
        }else{
            DLog(@"%@", retmsg);
            failureBlock(operation, [NSError errorWithDomain:@"error" code:code userInfo:@{@"message":retmsg }]);
        }
      
        
    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
        
        [SVProgressHUD dismiss];
        DLog(@"%@", error);
        if (error.userInfo) {
            
            NSMutableDictionary* userInfo=[NSMutableDictionary dictionaryWithDictionary:error.userInfo];
            
            [userInfo setObject:@"服务器异常，请稍后..." forKey:@"message"];
            
            error = [NSError errorWithDomain:@"error" code:error.code userInfo:userInfo];
            
        }
        
        failureBlock(operation, error);
       
        
    }];
    
    
}

+(BOOL)isNetworkExist    //检查网络情况
{
    BOOL isExistenceNetwork = YES;
    
    Reachability *r = [Reachability reachabilityWithHostname:@"www.apple.com"];
    switch ([r currentReachabilityStatus]) {
        case NotReachable:
            isExistenceNetwork=NO;
            DLog(@"没有网络");
            break;
        case ReachableViaWWAN:
            isExistenceNetwork=YES;
            DLog(@"正在使用3G网络");
            break;
        case ReachableViaWiFi:
            isExistenceNetwork=YES;
            DLog(@"正在使用wifi网络");
            break;
    }
    return isExistenceNetwork;
}

+(BOOL)is3GNetwork    //检查是否为3G网络
{
    BOOL is3GNetwork = YES;
    
    Reachability *r = [Reachability reachabilityWithHostname:@"www.apple.com"];
    switch ([r currentReachabilityStatus]) {
            
        case NotReachable:
            is3GNetwork=NO;
            //   NSLog(@"没有网络");
            break;
        case ReachableViaWWAN:
            is3GNetwork=YES;
            //   NSLog(@"正在使用3G网络");
            break;
        case ReachableViaWiFi:
            is3GNetwork=NO;
            //  NSLog(@"正在使用wifi网络");
            break;
            
    }
    return is3GNetwork;
}


@end
