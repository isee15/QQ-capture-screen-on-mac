//
//  HookUtil.h
//  Snip
//
//  Created by isee15 on 2019/5/7.
//  Copyright © 2019 isee15. All rights reserved.
//

#import <Foundation/Foundation.h>
//要特别注意你替换的方法到底是哪个性质的方法
// When swizzling a Instance method, use the following:
//        Class class = [self class];
// When swizzling a class method, use the following:
//Class class = object_getClass((id)self);
extern IMP class_swizzleSelector(Class clazz, SEL selector, IMP newImplementation);
extern IMP class_swizzleClassSelector(Class clazz, SEL selector, IMP newImplementation);

extern IMP class_swizzleSelectorWithBlock(Class clazz, SEL selector, id newImplementationBlock);
extern IMP class_swizzleClassSelectorWithBlock(Class clazz, SEL selector, id newImplementationBlock);

#define SwizzleSelector(clazz, selector, newImplementation, pPreviousImplementation) \
(*pPreviousImplementation) = (__typeof((*pPreviousImplementation)))class_swizzleSelector((clazz), (selector), (IMP)(newImplementation))

#define SwizzleClassSelector(clazz, selector, newImplementation, pPreviousImplementation) \
(*pPreviousImplementation) = (__typeof((*pPreviousImplementation)))class_swizzleClassSelector((clazz), (selector), (IMP)(newImplementation))

#define SwizzleSelectorWithBlock_Begin(clazz, selector) { \
SEL _cmd = selector; \
__block IMP _imp = class_swizzleSelectorWithBlock((clazz), (selector),
#define SwizzleSelectorWithBlock_End );}

#define SwizzleClassSelectorWithBlock_Begin(clazz, selector) { \
SEL _cmd = selector; \
__block IMP _imp = class_swizzleClassSelectorWithBlock((clazz), (selector),
#define SwizzleClassSelectorWithBlock_End );}


