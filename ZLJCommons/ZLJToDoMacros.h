//
//  Created by Johannes Zlattinger on 1/2/13.
//  Copyright (c) 2013 Johannes Zlattinger. All rights reserved.
//
//  see: https://github.com/AliSoftware/Xcode-Utils
//

#ifndef GENERATE_PRAGMA

#define GENERATE_PRAGMA(x) _Pragma(#x)

#endif

/* Usage: Use TODO("some message") / FIXME("some message") / NOTE("some message") to generate appropriate warnings */
#define TODO(x) GENERATE_PRAGMA(message("[TODO] " x))
#define FIXME(x) GENERATE_PRAGMA(message("[FIXME] " x))
#define NOTE(x) GENERATE_PRAGMA(message("[NOTE] " x))

/* Usage example:
 *     view.frame = CGRectMake(0, 0, MAGIC_NUMBER(77), MAGIC_NUMBER(90));
 *
 * It will warn you that you should replace values 77 and 90 with constants later, because magic numbers are bad.
 */
#define MAGIC_NUMBER(x) (({ FIXME("Replace magic number " #x " with constant") }), (x))

/* Usage example:
 *     NOT_IMPLEMENTED("This should show the details in a separate screen")
 *
 * Call this in some IBAction that you will implement later, to generate a warning
 * at compile time AND display an alert at runtime if the user trigger the IBAction
 */
#define NOT_IMPLEMENTED(warningMessage) \
        [[[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__] \
        message:[NSString stringWithFormat:@"%s",warningMessage] \
        delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show]; \
        TODO("Implement __PRETTY_FUNCTION__ - " warningMessage)
