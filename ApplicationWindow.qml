import QtQuick
import QtQuick.Templates
import Bootstrap

ApplicationWindow {
	id: window
	color: Bootstrap.bodyBg
	Overlay.modal: Rectangle {
		color: Color.transparent(window.palette.shadow, .5)
	}
	Overlay.modeless: Rectangle {
		color: Color.transparent(window.palette.shadow, .15)
	}
}
