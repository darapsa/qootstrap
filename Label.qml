import QtQuick 2.15
import QtQuick.Templates 2.15
import Bootstrap 5.3

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
