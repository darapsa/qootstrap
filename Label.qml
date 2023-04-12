import QtQuick 2.15
import QtQuick.Templates 2.15
import Bootstrap 5.3

Label {
	id: control
	font {
		family: Bootstrap.bodyFont.family
		pointSize: Bootstrap.bodyFont.pointSize
		weight: Bootstrap.bodyFont.weight
	}
	color: Bootstrap.bodyColor
	linkColor: control.palette.link
}
