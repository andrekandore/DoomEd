#import "Storage.h"

#import <appkit/appkit.h>

typedef struct
{
	NSRect	r;
	NSSize	imagesize;
	char	name[10];
	id		image;
} icon_t;

#define	SPACING		10
#define	ICONSIZE	48

@interface ThingPalette:NSObject
{
	id		window_i;			// outlet
	id		thingPalView_i;		// outlet
	id		thingPalScrView_i;	// outlet
	id		nameField_i;		// outlet

	CompatibleStorage *thingImages;		// Storage for icons
	int		currentIcon;		// currently selected icon
}

- menuTarget:sender;
- (int)findIcon:(char *)name;
- (icon_t *)getIcon:(int)which;
- (int)getCurrentIcon;
- setCurrentIcon:(int)which;
- (int)getNumIcons;
- computeThingDocView;
- initIcons;
- dumpAllIcons;


@end

extern ThingPalette *thingPalette_i;


