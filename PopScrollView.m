#import "PopScrollView.h"

@implementation PopScrollView

/*
====================
=
= initWithFrame: button:
=
= Initizes a scroll view with a button at it's lower right corner
=
====================
*/

- initWithFrame:(NSRect)frameRect button1:b1 button2:b2
{
	[super initWithFrame: frameRect];
	[self addSubview: b1];
	[self addSubview: b2];

	button1 = b1;
	button2 = b2;

	[self setHasHorizontalScroller: YES];
	[self setHasVerticalScroller: YES];
		
	return self;
}


/*
================
=
= tile
=
= Adjust the size for the pop up scale menu
=
=================
*/

- tile
{
	NSRect	scrollerframe;
	NSRect	buttonframe, buttonframe2;
	NSRect	newframe;
	
	[super tile];
	[button1 getFrame: &buttonframe];
	[button2 getFrame: &buttonframe2];
	[[self horizontalScroller] getFrame: &scrollerframe];

	newframe.origin.y = scrollerframe.origin.y;
	newframe.origin.x = [self frame].size.width - buttonframe.size.width;
	newframe.size.width = buttonframe.size.width;
	newframe.size.height = scrollerframe.size.height;
	scrollerframe.size.width -= newframe.size.width;
	[button1 setFrame: newframe];
	newframe.size.width = buttonframe2.size.width;
	newframe.origin.x -= newframe.size.width;
	[button2 setFrame: newframe];
	scrollerframe.size.width -= newframe.size.width;

	[[self horizontalScroller] setFrame: scrollerframe];

	return self;
}


@end

