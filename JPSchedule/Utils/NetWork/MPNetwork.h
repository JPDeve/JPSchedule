//
//  MPNetwork.h
//  maps
//
//  Created by Sencho Kong on 14-5-28.
//  Copyright (c) 2014年 zdnst. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"

#import <SystemConfiguration/SystemConfiguration.h>
#import "Reachability.h"

/**
 *  自定义封装成功返回的block
 *
 *  @param responseObject
 */
typedef void (^MPSuccessBlock)(id responseObject);

/**
 *  自定义封装失败返回的block
 *
 *  @param error
 */
typedef void (^MPFailureBlock)(NSError *error);

/**
 *  请求完成时返回的block
 *
 *  @param response
 *  @param responseObject
 *  @param error
 */
typedef void (^completionHandlerBlock)(NSURLResponse *response, id responseObject, NSError *error);

/**
 *  成功返回的block
 *
 *  @param operation
 *  @param responseObject
 */
typedef void (^successBlock)(AFHTTPRequestOperation *operation, id responseObject);

/**
 *  失败返回的block
 *
 *  @param operation
 *  @param error
 */
typedef void (^failureBlock)(AFHTTPRequestOperation *operation, NSError *error);

@interface MPNetwork : AFHTTPRequestOperationManager

/**
 *  MPNetwork 类方法
 *  @return 返回 MPNetwork 对象
 *
 *  @POST请求使用：
 *
 *  MPNetwork *manager = [MPNetwork manager];
 *  NSDictionary *parameters = @{@"foo": @"bar"};
 *  [manager requestWithMethod:@"POST"
 *                   URLString:@"http://example.com/resources.json"
 *                  parameters:parameters
 *                     success:^(AFHTTPRequestOperation *operation, id responseObject) {
 *                               NSLog(@"JSON: %@", responseObject);
 *                              }
 *                      failure:^(AFHTTPRequestOperation *operation, NSError *error) {
 *                               NSLog(@"Error: %@", error);
 *                              }];
 *
 *
 */
+ (instancetype)manager;

/**
 *  网络请求
 *
 *  @param method       HTTP请求方式 POST或GET
 *  @param URLString    请求的REST，如/login; 基础url已定义好，只需传入REST资源
 *  @param parameters   请求的参数,  @{@"foo": @"bar"};
 *  @param successBlock 成功返回的block
 *  @param failureBlock 失败返回的block
 *
 *  @return 返回一个 AFHTTPRequestOperation 对象
 */
- (AFHTTPRequestOperation *)requestWithMethod:(NSString*)method
                                    URLString:(NSString *)URLString
                                   parameters:(id)parameters
                                      success:(successBlock)successBlock
                                      failure:(failureBlock)failureBlock;


+(BOOL)isNetworkExist;    //检查网络情况

+(BOOL)is3GNetwork;    //检查是否为3G网络

@end