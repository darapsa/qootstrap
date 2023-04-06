#include <toml.h>
#include "bootstrap.hxx"

Bootstrap::Bootstrap(QObject *parent):
	QObject(parent),
	bs_mode(LightMode),
	bs_theme(None),
	bs_lightBodyBg("#fff"),
	bs_darkBodyBg("#212529")
{
	QFile conf{QStringLiteral(":/qtquickcontrols2.conf")};
	if (!conf.open(QIODevice::ReadOnly | QIODevice::Text)) return;
	auto toml = toml_parse(conf.readAll().data(), nullptr, 0);
	conf.close();
	auto bootstrap = toml_table_in(toml, "Bootstrap");
	if (bootstrap) {
		auto mode = toml_int_in(bootstrap, "Mode");
		if (mode.ok) bs_mode = static_cast<Mode>(mode.u.i);
	}
	toml_free(toml);
}

Bootstrap *Bootstrap::qmlAttachedProperties(QObject *object)
{
	return new Bootstrap(object);
}

Bootstrap::Mode Bootstrap::mode() const
{
	return bs_mode;
}

void Bootstrap::setMode(Mode mode)
{
	if (mode == bs_mode) return;
	bs_mode = mode;
	emit modeChanged();
	emit bodyBgChanged();
}

Bootstrap::Theme Bootstrap::theme() const
{
	return bs_theme;
}

void Bootstrap::setTheme(Theme theme)
{
	if (theme == bs_theme) return;
	bs_theme = theme;
	emit themeChanged();
}

QColor Bootstrap::bodyBg() const
{
	return bs_mode ? bs_darkBodyBg : bs_lightBodyBg;
}

void Bootstrap::setLightBodyBg(QColor lightBodyBg)
{
	if (lightBodyBg == bs_lightBodyBg) return;
	bs_lightBodyBg = lightBodyBg;
	emit bodyBgChanged();
}

void Bootstrap::setDarkBodyBg(QColor darkBodyBg)
{
	if (darkBodyBg == bs_darkBodyBg) return;
	bs_darkBodyBg = darkBodyBg;
	emit bodyBgChanged();
}
