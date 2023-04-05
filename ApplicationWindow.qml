import QtQuick 2.15
import QtQuick.Templates 2.15
import Bootstrap 5.3

ApplicationWindow {
	id: window
	color: Bootstrap.bodyBg
	overlay {
		modal: Rectangle {
			color: Color.transparent(window.palette.shadow, .5)
		}
		modeless: Rectangle {
			color: Color.transparent(window.palette.shadow, .15)
		}
	}
}
