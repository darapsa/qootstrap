pragma Singleton
import QtQuick 2.15

QtObject {
	enum Theme {
		Light = 0,
		Dark
	}
	property int theme: Bootstrap.Theme.Light

	property color accordionBg: bodyBg

	property real badgeFontSize: 13.6

	property color bodyColor: theme ? "#a1a1a8" : "#747579"
	property color bodyBg: theme ? "#222529" : "#ffffff"

	property color borderColor: theme ? "#12ffffff" : gray200
	property real borderRadius: 5.2

	property real boxShadowOffsetX: 0
	property real boxShadowOffsetY: 0
	property int boxShadowBlurRadius: 40
	property color boxShadowColor: "#261d3a53"

	property real btnPaddingX: 16
	property real btnPaddingY: 8

	property color btnColor: "#747579"
	property color btnBg: "transparent"
	property color btnBorderColor: btnBg
	property real btnBorderWidth: 1
	property real btnBorderRadius: 5.2
	property real btnLgFontSize: 16
	property real btnLgBorderRadius: 8

	property color primary: "#066ac9"
	property color secondary: "#9a9ea4"
	property color success: "#0cbc87"
	property color danger: "#d6293e"
	property color light: theme ? "#2a2c31" : "#f5f7f9"
	property color dark: theme ? "#0f0f10" : "#24292d"
	property color tertiaryBg: theme ? "#2b3035" : "#f8f9fa"

	property color btnPrimaryColor: "#ffffff"
	property color btnPrimaryBg: primary
	property color btnPrimaryBorderColor: primary
	property color btnPrimaryActiveColor: btnPrimaryColor
	property color btnPrimaryActiveBg: "#0555a1"
	property color btnPrimaryActiveBorderColor: "#055097"
	property color btnPrimaryDisabledColor: "#a6ffffff"
	property color btnPrimaryDisabledBg: "#a6066ac9"
	property color btnPrimaryDisabledBorderColor: btnPrimaryDisabledBg

	property color btnOutlinePrimaryColor: primary
	property color btnOutlinePrimaryBg: btnBg
	property color btnOutlinePrimaryBorderColor: primary
	property color btnOutlinePrimaryActiveColor: btnPrimaryColor
	property color btnOutlinePrimaryActiveBg: primary
	property color btnOutlinePrimaryActiveBorderColor: primary
	property color btnOutlinePrimaryDisabledColor:
						btnPrimaryDisabledColor
	property color btnOutlinePrimaryDisabledBg: btnBg
	property color btnOutlinePrimaryDisabledBorderColor:
						btnPrimaryDisabledColor

	property color btnSuccessColor: btnPrimaryColor
	property color btnSuccessBg: success
	property color btnSuccessBorderColor: success
	property color btnSuccessActiveColor: btnSuccessColor
	property color btnSuccessActiveBg: "#0a966c"
	property color btnSuccessActiveBorderColor: "#098d65"
	property color btnSuccessDisabledColor: btnPrimaryDisabledColor
	property color btnSuccessDisabledBg: "#a60cbc87"
	property color btnSuccessDisabledBorderColor: btnSuccessDisabledBg

	property color btnLightColor: "#000000"
	property color btnLightBg: "#f5f7f9"
	property color btnLightBorderColor: btnLightBg
	property color btnLightActiveColor: btnLightColor
	property color btnLightActiveBg: "#c4c6c7"
	property color btnLightActiveBorderColor: "#b8b9bb"
	property color btnLightDisabledColor: "#a6000000"
	property color btnLightDisabledBg: "#a6f5f7f9"
	property color btnLightDisabledBorderColor: btnLightDisabledBg

	property color cardBg: theme ? "#1b1e21" : "#ffffff"
	property color cardTitleColor: theme ? "#f7f5f5" : "#24292d"

	property color dropdownColor: "#747579"
	property color dropdownLinkColor: theme ? "#c5c6cc" : "#747579"
	property color dropdownLinkHoverColor: "#066ac9"
	property color dropdownLinkHoverBg: "#1a066ac9"

	property color headingColor: theme ? "#ffffff" : "#24292d"

	property color gray200: theme ? "#464950" : "#eff1f2"
	property color gray300: theme ? "#3e3e40" : "#dde0e3"
	property color gray500: theme ? "#bfc0c9" : "#9a9ea4"
	property color gray600: theme ? "#c5c6cc" : "#747579"
	property color gray700: theme ? "#f3f1f1" : "#404448"
	property color gray800: theme ? "#f7f5f5" : "#24292d"
	property color gray900: theme ? "#ffffff" : "#0b0f13"
}
