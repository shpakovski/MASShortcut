#import <Carbon/Carbon.h>

// These glyphs are missed in Carbon.h
enum {
    kMASShortcutGlyphEject = 0x23CF,
    kMASShortcutGlyphClear = 0x2715,
	kMASShortcutGlyphDeleteLeft = 0x232B,
	kMASShortcutGlyphDeleteRight = 0x2326,
    kMASShortcutGlyphLeftArrow = 0x2190,
	kMASShortcutGlyphRightArrow = 0x2192,
	kMASShortcutGlyphUpArrow = 0x2191,
	kMASShortcutGlyphDownArrow = 0x2193,
	kMASShortcutGlyphEscape = 0x238B,
	kMASShortcutGlyphHelp = 0x003F,
    kMASShortcutGlyphPageDown = 0x21DF,
	kMASShortcutGlyphPageUp = 0x21DE,
	kMASShortcutGlyphTabRight = 0x21E5,
	kMASShortcutGlyphReturn = 0x2305,
	kMASShortcutGlyphReturnR2L = 0x21A9,	
	kMASShortcutGlyphPadClear = 0x2327,
	kMASShortcutGlyphNorthwestArrow = 0x2196,
	kMASShortcutGlyphSoutheastArrow = 0x2198,
} MASShortcutGlyph;

NS_INLINE NSString* NSStringFromMASKeyCode(unsigned short ch)
{
    return [NSString stringWithFormat:@"%C", ch];
}

NS_INLINE NSUInteger MASPickCocoaModifiers(NSUInteger flags)
{
    return (flags & (NSControlKeyMask | NSShiftKeyMask | NSAlternateKeyMask | NSCommandKeyMask));
}

NS_INLINE UInt32 MASCarbonModifiersFromCocoaModifiers(NSUInteger cocoaFlags)
{
    return
          (cocoaFlags & NSCommandKeyMask ? cmdKey : 0)
        | (cocoaFlags & NSAlternateKeyMask ? optionKey : 0)
        | (cocoaFlags & NSControlKeyMask ? controlKey : 0)
        | (cocoaFlags & NSShiftKeyMask ? shiftKey : 0);
}
