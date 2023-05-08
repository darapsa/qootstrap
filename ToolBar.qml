import QtQuick 2.15
import QtQuick.Templates 2.15
import Bootstrap 5.3

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
