#include "tomlc99/toml.h"
#include "Bootstrap.hxx"

Bootstrap::Bootstrap(QObject *parent):
	QObject(parent),
	bsTheme(None),
	bsDarkMode(false),
	bsLightBodyBg("#fff"),
	bsDarkBodyBg("#212529")
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
	auto darkMode = toml_bool_in(bootstrap, "DarkMode");
	if (darkMode.ok) bsDarkMode = darkMode.u.b;
	auto bodyBg = toml_array_in(bootstrap, "BodyBg");
	if (bodyBg) {
		auto lightBodyBg = toml_string_at(bodyBg, 0).u.s;
		bsLightBodyBg = QColor{lightBodyBg};
		free(lightBodyBg);
		auto darkBodyBg = toml_string_at(bodyBg, 1).u.s;
		bsDarkBodyBg = QColor{darkBodyBg};
		free(darkBodyBg);
	}
	toml_free(toml);
}

Bootstrap *Bootstrap::qmlAttachedProperties(QObject *object)
{
	return new Bootstrap(object);
}

bool Bootstrap::darkMode() const
{
	return bsDarkMode;
}

void Bootstrap::setDarkMode(bool darkMode)
{
	if (darkMode == bsDarkMode) return;
	bsDarkMode = darkMode;
	emit darkModeChanged();
	emit bodyBgChanged();
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

QColor Bootstrap::bodyBg() const
{
	return bsDarkMode ? bsDarkBodyBg : bsLightBodyBg;
}
