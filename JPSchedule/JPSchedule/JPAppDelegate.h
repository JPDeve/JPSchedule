//
//  JPAppDelegate.h
//  JPSchedule
//
//  Created by pody on 14-8-10.
//  Copyright (c) 2014年 JP. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface JPAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;

@end
