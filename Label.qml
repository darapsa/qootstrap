import QtQuick
import QtQuick.Templates
import Bootstrap

Label {
	id: control
	font {
		family: Bootstrap.heading
				? Bootstrap.headingFont.family
				: Bootstrap.bodyFont.family
		pointSize: Bootstrap.heading
				? Bootstrap.headingFontSize(parent.width)
				: Bootstrap.bodyFont.pointSize
		weight: Bootstrap.heading
				? Bootstrap.headingFont.weight
				: Bootstrap.bodyFont.weight
	}
	color: Bootstrap.heading
			? Bootstrap.headingColor
			: Bootstrap.bodyColor
	linkColor: control.palette.link
}
