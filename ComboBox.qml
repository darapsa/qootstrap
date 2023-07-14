import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.impl 2.15
import QtQuick.Templates 2.15 as T
import Bootstrap 5.3

T.ComboBox {
	id: control
	font: Bootstrap.bodyFont

	implicitWidth: Math.max(implicitBackgroundWidth
		+ leftInset + rightInset,
	implicitContentWidth + leftPadding + rightPadding)
	implicitHeight: Math.max(implicitBackgroundHeight
		+ topInset + bottomInset,
	implicitContentHeight + topPadding + bottomPadding,
	implicitIndicatorHeight + topPadding + bottomPadding)

	leftPadding: padding
		+ (!control.mirrored || !indicator || !indicator.visible
		? 0 : indicator.width + spacing)
	rightPadding: padding
		+ (control.mirrored || !indicator || !indicator.visible
		? 0 : indicator.width + spacing)

	delegate: ItemDelegate {
		width: ListView.view.width
		palette.text: control.palette.text
		palette.highlightedText: control.palette.highlightedText
		font.weight: control.currentIndex === index
			? Font.DemiBold : Font.Normal
		highlighted: control.highlightedIndex === index
		hoverEnabled: control.hoverEnabled
		contentItem: Text {
			text: control.textRole ? (Array.isArray(control.model)
				? modelData[control.textRole]
				: model[control.textRole]) : modelData
			font: control.font
			color: Bootstrap.bodyColor
			verticalAlignment: Text.AlignVCenter
		}
		background: Rectangle {
			color: Bootstrap.bodyBg
		}
	}

	indicator: ColorImage {
		x: control.mirrored ? control.padding
			: control.width - width - control.padding
		y: control.topPadding + (control.availableHeight - height) / 2
		color: control.palette.dark
		defaultColor: "#353637"
		source: "qrc:/qt-project.org/imports/QtQuick/Controls.2/images/double-arrow.png"
		opacity: enabled ? 1 : 0.3
	}

	contentItem: T.TextField {
		leftPadding: !control.mirrored
			? 12 : control.editable && activeFocus ? 3 : 1
		rightPadding: control.mirrored
			? 12 : control.editable && activeFocus ? 3 : 1
		topPadding: 6 - control.padding
		bottomPadding: 6 - control.padding

		text: control.editable ? control.editText : control.displayText

		enabled: control.editable
		autoScroll: control.editable
		readOnly: control.down
		inputMethodHints: control.inputMethodHints
		validator: control.validator
		selectByMouse: control.selectTextByMouse

		font: control.font
		color: Bootstrap.bodyColor
		selectionColor: control.palette.highlight
		selectedTextColor: control.palette.highlightedText
		verticalAlignment: Text.AlignVCenter

		background: Rectangle {
			visible: control.enabled && control.editable
				&& !control.flat
			border.width: parent && parent.activeFocus ? 2 : 1
			border.color: parent && parent.activeFocus
				? control.palette.highlight
				: control.palette.button
			color: Bootstrap.bodyBg
		}
	}

	background: Rectangle {
		implicitWidth: 140
		implicitHeight: 40

		color: Bootstrap.bodyBg
		border.color: control.palette.highlight
		border.width: !control.editable && control.visualFocus ? 2 : 0
		visible: !control.flat || control.down
		radius: 8
	}

	popup: T.Popup {
		y: control.height
		width: control.width
		height: Math.min(contentItem.implicitHeight,
			control.Window.height - topMargin - bottomMargin)
		topMargin: 6
		bottomMargin: 6

		contentItem: ListView {
			clip: true
			implicitHeight: contentHeight
			model: control.delegateModel
			currentIndex: control.highlightedIndex
			highlightMoveDuration: 0

			Rectangle {
				z: 10
				width: parent.width
				height: parent.height
				color: "transparent"
				border.color: control.palette.mid
			}

			T.ScrollIndicator.vertical: ScrollIndicator { }
		}

		background: Rectangle {
			color: Bootstrap.bodyBg
		}
	}
}
