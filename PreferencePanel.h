
#import <appkit/appkit.h>

#define	APPDEFAULTS	"ID_doomed"
//	#define NUMCOLORS	9
#define	PREFNAME		@"PrefPanel"

typedef enum
{
	BACK_C = 0,
	GRID_C,
	TILE_C,
	SELECTED_C,
	POINT_C,
	ONESIDED_C,
	TWOSIDED_C,
	AREA_C,
	THING_C,
	SPECIAL_C,
	NUMCOLORS
} ucolor_e;

typedef enum
{
	texturePalette,
	lineInspector,
	lineSpecials,
	errorLog,
	sectorEditor,
	thingPanel,
	sectorSpecials,
	textureEditor,
	NUMOPENUP
} openup_e;

@interface PreferencePanel:NSObject
{
    id	backcolor_i;
    id	gridcolor_i;
    id	tilecolor_i;
    id	selectedcolor_i;
    id	pointcolor_i;
    id	onesidedcolor_i;
    id	twosidedcolor_i;
    id	areacolor_i;
    id	thingcolor_i;
	id	specialcolor_i;
	
	id	launchThingType_i;
	id	projectDefaultPath_i;
	id	openupDefaults_i;
	
    id	window_i;
	
	id		colorwell[NUMCOLORS];
	NSColor	*color[NUMCOLORS];
	int		launchThingType;
	char	projectPath[128];
}

- menuTarget:sender;
- colorChanged:sender;
- launchThingTypeChanged:sender;
- projectPathChanged:sender;
- openupChanged:sender;

- applicationWillTerminate: (NSNotification *)notification;

//
//	DoomEd accessor methods
//
- (NSColor *)colorFor: (int)ucolor;
- (int)getLaunchThingType;
- (char *)getProjectPath;
- (BOOL)openUponLaunch:(openup_e)type;

@end

extern PreferencePanel *prefpanel_i;

