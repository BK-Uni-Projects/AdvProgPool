#ifndef COLOURS_H_INCLUDED
#define COLOURS_H_INCLUDED


inline GLfloat RandColourVal(){
	return rand() / (RAND_MAX + 1.0f);
}

// Named colours for use with opengl r, g, b system

GLfloat ALICEBLUE[] = { 0.94f, 0.97f, 1.00f };
GLfloat ANTIQUEWHITE[] = { 0.98f, 0.92f, 0.84f };
GLfloat AQUA[] = { 0.00f, 1.00f, 1.00f };
GLfloat AQUAMARINE[] = { 0.50f, 1.00f, 0.83f };
GLfloat AZURE[] = { 0.94f, 1.00f, 1.00f };
GLfloat BEIGE[] = { 0.96f, 0.96f, 0.86f };
GLfloat BISQUE[] = { 1.00f, 0.89f, 0.77f };
GLfloat BLACK[] = { 0.00f, 0.00f, 0.00f };
GLfloat BLANCHEDALMOND[] = { 1.00f, 0.92f, 0.80f };
GLfloat BLUE[] = { 0.00f, 0.00f, 1.00f };
GLfloat BLUEVIOLET[] = { 0.54f, 0.17f, 0.88f };
GLfloat BROWN[] = { 0.64f, 0.16f, 0.16f };
GLfloat BURLYWOOD[] = { 0.87f, 0.72f, 0.53f };
GLfloat CADETBLUE[] = { 0.37f, 0.62f, 0.62f };
GLfloat CHARTREUSE[] = { 0.50f, 1.00f, 0.00f };
GLfloat CHOCOLATE[] = { 0.82f, 0.41f, 0.12f };
GLfloat CORAL[] = { 1.00f, 0.50f, 0.31f };
GLfloat CORNFLOWERBLUE[] = { 0.39f, 0.58f, 0.93f };
GLfloat CORNSILK[] = { 1.00f, 0.97f, 0.86f };
GLfloat CRIMSON[] = { 0.86f, 0.08f, 0.23f };
GLfloat CYAN[] = { 0.00f, 1.00f, 1.00f };
GLfloat DARKBLUE[] = { 0.00f, 0.00f, 0.54f };
GLfloat DARKCYAN[] = { 0.00f, 0.54f, 0.54f };
GLfloat DARKGOLDENROD[] = { 0.72f, 0.52f, 0.04f };
GLfloat DARKGRAY[] = { 0.66f, 0.66f, 0.66f };
GLfloat DARKGREY[] = { 0.66f, 0.66f, 0.66f };
GLfloat DARKGREEN[] = { 0.00f, 0.39f, 0.00f };
GLfloat DARKKHAKI[] = { 0.74f, 0.71f, 0.42f };
GLfloat DARKMAGENTA[] = { 0.54f, 0.00f, 0.54f };
GLfloat DARKOLIVEGREEN[] = { 0.33f, 0.42f, 0.18f };
GLfloat DARKORANGE[] = { 1.00f, 0.55f, 0.00f };
GLfloat DARKORCHID[] = { 0.60f, 0.20f, 0.80f };
GLfloat DARKRED[] = { 0.54f, 0.00f, 0.00f };
GLfloat DARKSALMON[] = { 0.91f, 0.59f, 0.48f };
GLfloat DARKSEAGREEN[] = { 0.56f, 0.73f, 0.56f };
GLfloat DARKSLATEBLUE[] = { 0.28f, 0.24f, 0.54f };
GLfloat DARKSLATEGRAY[] = { 0.18f, 0.31f, 0.31f };
GLfloat DARKSLATEGREY[] = { 0.18f, 0.31f, 0.31f };
GLfloat DARKTURQUOISE[] = { 0.00f, 0.80f, 0.82f };
GLfloat DARKVIOLET[] = { 0.58f, 0.00f, 0.82f };
GLfloat DEEPPINK[] = { 1.00f, 0.08f, 0.57f };
GLfloat DEEPSKYBLUE[] = { 0.00f, 0.75f, 1.00f };
GLfloat DIMGRAY[] = { 0.41f, 0.41f, 0.41f };
GLfloat DIMGREY[] = { 0.41f, 0.41f, 0.41f };
GLfloat DODGERBLUE[] = { 0.12f, 0.56f, 1.00f };
GLfloat FIREBRICK[] = { 0.70f, 0.13f, 0.13f };
GLfloat FLORALWHITE[] = { 1.00f, 0.98f, 0.94f };
GLfloat FORESTGREEN[] = { 0.13f, 0.54f, 0.13f };
GLfloat FUCHSIA[] = { 1.00f, 0.00f, 1.00f };
GLfloat GAINSBORO[] = { 0.86f, 0.86f, 0.86f };
GLfloat GHOSTWHITE[] = { 0.97f, 0.97f, 1.00f };
GLfloat GOLD[] = { 1.00f, 0.84f, 0.00f };
GLfloat GOLDENROD[] = { 0.85f, 0.64f, 0.12f };
GLfloat GRAY[] = { 0.50f, 0.50f, 0.50f };
GLfloat GREY[] = { 0.50f, 0.50f, 0.50f };
GLfloat GREEN[] = { 0.00f, 0.50f, 0.00f };
GLfloat GREENYELLOW[] = { 0.68f, 1.00f, 0.18f };
GLfloat HONEYDEW[] = { 0.94f, 1.00f, 0.94f };
GLfloat HOTPINK[] = { 1.00f, 0.41f, 0.70f };
GLfloat INDIANRED[] = { 0.80f, 0.36f, 0.36f };
GLfloat INDIGO[] = { 0.29f, 0.00f, 0.51f };
GLfloat IVORY[] = { 1.00f, 1.00f, 0.94f };
GLfloat KHAKI[] = { 0.94f, 0.90f, 0.55f };
GLfloat LAVENDER[] = { 0.90f, 0.90f, 0.98f };
GLfloat LAVENDERBLUSH[] = { 1.00f, 0.94f, 0.96f };
GLfloat LAWNGREEN[] = { 0.48f, 0.98f, 0.00f };
GLfloat LEMONCHIFFON[] = { 1.00f, 0.98f, 0.80f };
GLfloat LIGHTBLUE[] = { 0.68f, 0.84f, 0.90f };
GLfloat LIGHTCORAL[] = { 0.94f, 0.50f, 0.50f };
GLfloat LIGHTCYAN[] = { 0.88f, 1.00f, 1.00f };
GLfloat LIGHTGOLDENRODYELLOW[] = { 0.98f, 0.98f, 0.82f };
GLfloat LIGHTGRAY[] = { 0.82f, 0.82f, 0.82f };
GLfloat LIGHTGREY[] = { 0.82f, 0.82f, 0.82f };
GLfloat LIGHTGREEN[] = { 0.56f, 0.93f, 0.56f };
GLfloat LIGHTPINK[] = { 1.00f, 0.71f, 0.75f };
GLfloat LIGHTSALMON[] = { 1.00f, 0.62f, 0.48f };
GLfloat LIGHTSEAGREEN[] = { 0.12f, 0.70f, 0.66f };
GLfloat LIGHTSKYBLUE[] = { 0.53f, 0.80f, 0.98f };
GLfloat LIGHTSLATEGRAY[] = { 0.46f, 0.53f, 0.60f };
GLfloat LIGHTSLATEGREY[] = { 0.46f, 0.53f, 0.60f };
GLfloat LIGHTSTEELBLUE[] = { 0.69f, 0.77f, 0.87f };
GLfloat LIGHTYELLOW[] = { 1.00f, 1.00f, 0.88f };
GLfloat LIME[] = { 0.00f, 1.00f, 0.00f };
GLfloat LIMEGREEN[] = { 0.20f, 0.80f, 0.20f };
GLfloat LINEN[] = { 0.98f, 0.94f, 0.90f };
GLfloat MAGENTA[] = { 1.00f, 0.00f, 1.00f };
GLfloat MAROON[] = { 0.50f, 0.00f, 0.00f };
GLfloat MEDIUMAQUAMARINE[] = { 0.40f, 0.80f, 0.66f };
GLfloat MEDIUMBLUE[] = { 0.00f, 0.00f, 0.80f };
GLfloat MEDIUMORCHID[] = { 0.73f, 0.33f, 0.82f };
GLfloat MEDIUMPURPLE[] = { 0.57f, 0.44f, 0.86f };
GLfloat MEDIUMSEAGREEN[] = { 0.23f, 0.70f, 0.44f };
GLfloat MEDIUMSLATEBLUE[] = { 0.48f, 0.41f, 0.93f };
GLfloat MEDIUMSPRINGGREEN[] = { 0.00f, 0.98f, 0.60f };
GLfloat MEDIUMTURQUOISE[] = { 0.28f, 0.82f, 0.80f };
GLfloat MEDIUMVIOLETRED[] = { 0.78f, 0.08f, 0.52f };
GLfloat MIDNIGHTBLUE[] = { 0.10f, 0.10f, 0.44f };
GLfloat MINTCREAM[] = { 0.96f, 1.00f, 0.98f };
GLfloat MISTYROSE[] = { 1.00f, 0.89f, 0.88f };
GLfloat MOCCASIN[] = { 1.00f, 0.89f, 0.71f };
GLfloat NAVAJOWHITE[] = { 1.00f, 0.87f, 0.68f };
GLfloat NAVY[] = { 0.00f, 0.00f, 0.50f };
GLfloat OLDLACE[] = { 0.99f, 0.96f, 0.90f };
GLfloat OLIVE[] = { 0.50f, 0.50f, 0.00f };
GLfloat OLIVEDRAB[] = { 0.42f, 0.55f, 0.14f };
GLfloat ORANGE[] = { 1.00f, 0.64f, 0.00f };
GLfloat ORANGERED[] = { 1.00f, 0.27f, 0.00f };
GLfloat ORCHID[] = { 0.85f, 0.44f, 0.84f };
GLfloat PALEGOLDENROD[] = { 0.93f, 0.91f, 0.66f };
GLfloat PALEGREEN[] = { 0.59f, 0.98f, 0.59f };
GLfloat PALETURQUOISE[] = { 0.68f, 0.93f, 0.93f };
GLfloat PALEVIOLETRED[] = { 0.86f, 0.44f, 0.57f };
GLfloat PAPAYAWHIP[] = { 1.00f, 0.93f, 0.83f };
GLfloat PEACHPUFF[] = { 1.00f, 0.85f, 0.72f };
GLfloat PERU[] = { 0.80f, 0.52f, 0.25f };
GLfloat PINK[] = { 1.00f, 0.75f, 0.79f };
GLfloat PLUM[] = { 0.86f, 0.62f, 0.86f };
GLfloat POWDERBLUE[] = { 0.69f, 0.88f, 0.90f };
GLfloat PURPLE[] = { 0.50f, 0.00f, 0.50f };
GLfloat REBECCAPURPLE[] = { 0.40f, 0.20f, 0.60f };
GLfloat RED[] = { 1.00f, 0.00f, 0.00f };
GLfloat ROSYBROWN[] = { 0.73f, 0.56f, 0.56f };
GLfloat ROYALBLUE[] = { 0.25f, 0.41f, 0.88f };
GLfloat SADDLEBROWN[] = { 0.54f, 0.27f, 0.07f };
GLfloat SALMON[] = { 0.98f, 0.50f, 0.45f };
GLfloat SANDYBROWN[] = { 0.95f, 0.64f, 0.38f };
GLfloat SEAGREEN[] = { 0.18f, 0.54f, 0.34f };
GLfloat SEASHELL[] = { 1.00f, 0.96f, 0.93f };
GLfloat SIENNA[] = { 0.62f, 0.32f, 0.18f };
GLfloat SILVER[] = { 0.75f, 0.75f, 0.75f };
GLfloat SKYBLUE[] = { 0.53f, 0.80f, 0.92f };
GLfloat SLATEBLUE[] = { 0.41f, 0.35f, 0.80f };
GLfloat SLATEGRAY[] = { 0.44f, 0.50f, 0.56f };
GLfloat SLATEGREY[] = { 0.44f, 0.50f, 0.56f };
GLfloat SNOW[] = { 1.00f, 0.98f, 0.98f };
GLfloat SPRINGGREEN[] = { 0.00f, 1.00f, 0.50f };
GLfloat STEELBLUE[] = { 0.27f, 0.51f, 0.70f };
GLfloat TAN[] = { 0.82f, 0.70f, 0.55f };
GLfloat TEAL[] = { 0.00f, 0.50f, 0.50f };
GLfloat THISTLE[] = { 0.84f, 0.75f, 0.84f };
GLfloat TOMATO[] = { 1.00f, 0.39f, 0.28f };
GLfloat TURQUOISE[] = { 0.25f, 0.88f, 0.81f };
GLfloat VIOLET[] = { 0.93f, 0.51f, 0.93f };
GLfloat WHEAT[] = { 0.96f, 0.87f, 0.70f };
GLfloat WHITE[] = { 1.00f, 1.00f, 1.00f };
GLfloat WHITESMOKE[] = { 0.96f, 0.96f, 0.96f };
GLfloat YELLOW[] = { 1.00f, 1.00f, 0.00f };
GLfloat YELLOWGREEN[] = { 0.60f, 0.80f, 0.20f };


#endif // COLOURS_H_INCLUDED/n