#include "tomlc99/toml.h"
#include "Bootstrap.hxx"

#define OVERRIDE_COLORS(A, B) \
	colors = toml_array_in(bootstrap, A);\
	if (colors) for (int i = 0; ; i++) {\
		auto color = toml_string_at(colors, i);\
		if (!color.ok) break;\
		B[i] = QColor{color.u.s};\
		free(color.u.s);\
	}
	
Bootstrap::Bootstrap(QObject *parent):
	QObject{parent},
	bsMode{Mode::Light},
	bsTheme{Theme::None},
	bodyColors{{"#212529", "#adb5bd"}},
	bodyBgs{{"#fff", "#212529"}},
	borderColors{{"#dee2e6", "#495057"}}
{
	QFile conf{QStringLiteral(":/qtquickcontrols2.conf")};
	if (!conf.open(QIODevice::ReadOnly | QIODevice::Text)) return;
	auto toml = toml_parse(conf.readAll().data(), nullptr, 0);
	conf.close();

	auto bootstrap = toml_table_in(toml, "Bootstrap");
	if (!bootstrap) {
		toml_free(toml);
		return;
	}

	auto mode = toml_int_in(bootstrap, "Mode");
	if (mode.ok) bsMode = static_cast<Mode>(mode.u.i);

	toml_array_t *colors;
	OVERRIDE_COLORS("BodyColors", bodyColors);
	OVERRIDE_COLORS("BodyBgs", bodyBgs);
	OVERRIDE_COLORS("BorderColors", borderColors);

	toml_free(toml);
}

Bootstrap *Bootstrap::qmlAttachedProperties(QObject *object)
{
	return new Bootstrap(object);
}

Bootstrap::Mode Bootstrap::mode() const
{
	return bsMode;
}

void Bootstrap::setMode(Mode mode)
{
	if (mode == bsMode) return;
	bsMode = mode;
	emit modeChanged();
	emit bodyColorChanged();
	emit bodyBgChanged();
	emit borderColorChanged();
}

Bootstrap::Theme Bootstrap::theme() const
{
	return bsTheme;
}

void Bootstrap::setTheme(Theme theme)
{
	if (theme == bsTheme) return;
	bsTheme = theme;
	emit themeChanged();
}

QColor Bootstrap::bodyColor() const
{
	return bodyColors.at(static_cast<int>(bsMode));
}

QColor Bootstrap::bodyBg() const
{
	return bodyBgs.at(static_cast<int>(bsMode));
}

QColor Bootstrap::borderColor() const
{
	return borderColors.at(static_cast<int>(bsMode));
}
