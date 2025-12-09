import QtQuick
import QtQuick.Templates
import Bootstrap

ToolBar {
	id: control
	implicitWidth: Math.max(implicitBackgroundWidth
			+ leftInset + rightInset,
			contentWidth + leftPadding + rightPadding)
	implicitHeight: Math.max(implicitBackgroundHeight
			+ topInset + bottomInset,
			contentHeight + topPadding + bottomPadding)
	background: Rectangle {
		implicitHeight: 40
		color: control.Bootstrap.bodyBg
	}
}
