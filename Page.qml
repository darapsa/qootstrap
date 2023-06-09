import QtQuick 2.15
import QtQuick.Templates 2.15
import Bootstrap 5.3

Page {
	id: control
	implicitWidth: Math.max(implicitBackgroundWidth
			+ leftInset + rightInset,
			contentWidth + leftPadding + rightPadding,
			implicitHeaderWidth,
			implicitFooterWidth)
	implicitHeight: Math.max(implicitBackgroundHeight
			+ topInset + bottomInset,
			contentHeight + topPadding + bottomPadding
			+ (implicitHeaderHeight > 0
				? implicitHeaderHeight + spacing : 0)
			+ (implicitFooterHeight > 0
				? implicitFooterHeight + spacing : 0))
	background: Rectangle {
		color: control.Bootstrap.bodyBg
	}
}
