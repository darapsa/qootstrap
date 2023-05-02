#include "tomlc99/toml.h"
#include "Bootstrap.hxx"

#define OVERRIDE_FONT_FAMILY(A, B) \
	{\
		auto fontFamily = toml_string_in(bootstrap, A);\
		if (fontFamily.ok) {\
			B.setFamily(fontFamily.u.s);\
			free(fontFamily.u.s);\
			bsBodyFont.setStyleHint(QFont::AnyStyle);\
		}\
	}

#define OVERRIDE_FONT_SIZE(A, B) \
	{\
		auto fontSize = toml_double_in(bootstrap, A);\
		if (fontSize.ok) B.setPointSizeF(fontSize.u.d);\
	}

#define OVERRIDE_FONT_WEIGHT(A, B) \
	{\
		auto fontWeight = toml_int_in(bootstrap, A);\
		if (fontWeight.ok) B.setWeight(fontWeight.u.i);\
	}

#define OVERRIDE_COLORS(A, B) \
	colors = toml_array_in(bootstrap, A);\
	if (colors) for (int i = 0; ; i++) {\
		auto color = toml_string_at(colors, i);\
		if (!color.ok) break;\
		B[i] = QColor{color.u.s};\
		free(color.u.s);\
	}

#define OVERRIDE_HX_FONT_SIZE(A, B) \
	size = toml_array_in(bootstrap, A);\
	if (size) {\
		auto rem = toml_double_at(size, 0);\
		if (rem.ok) B[0] = rem.u.d * 16.0;\
		auto factor = toml_double_at(size, 1);\
		if (factor.ok) B[1] = factor.u.d / 100.0;\
	}

Bootstrap::Bootstrap(QObject *parent):
	QObject{parent},
	bsMode{Mode::Light},
	bsTheme{Theme::None},
#ifdef __ANDROID__
	bsFontSansSerif{"Roboto"},
#elif defined(__APPLE__)
	bsFontSansSerif{"Helvetica Neue"},
#elif defined(__EMSCRIPTEN__)
	bsFontSansSerif{"Arial"},
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32) \
		|| defined(_WIN64) || defined(__WIN64)
	bsFontSansSerif{"Segoe UI"},
#else
	bsFontSansSerif{"Liberation Sans"},
#endif
	bsBodyFont{bsFontSansSerif},
	bodyColors{{"#212529", "#adb5bd"}},
	bodyBgs{{"#fff", "#212529"}},
	borderColors{{"#dee2e6", "#495057"}},
	htmlHeading{0},
	bsHeadingFont{bsFontSansSerif},
	headingColors{{bodyColors.at(0), bodyColors.at(1)}},
	h1FontSize{{22.0, .015}},
	h2FontSize{{21.2, .009}},
	h3FontSize{{20.8, .006}},
	h4FontSize{{20.4, .003}},
	h5FontSize{{20.0, .0}},
	h6FontSize{{16.0, .0}},
	cardBgs{{bodyBgs.at(0), bodyBgs.at(1)}}
{
	bsBodyFont.setStyleHint(QFont::SansSerif);
	bsBodyFont.setPointSizeF(16.0);
	bsBodyFont.setWeight(QFont::Normal);

	bsHeadingFont.setStyleHint(QFont::SansSerif);
	bsHeadingFont.setPointSizeF(16.0);
	bsHeadingFont.setWeight(QFont::Medium);

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

	OVERRIDE_FONT_FAMILY("BodyFontFamily", bsBodyFont);
	OVERRIDE_FONT_SIZE("BodyFontSize", bsBodyFont);
	OVERRIDE_FONT_WEIGHT("BodyFontWeight", bsBodyFont);

	toml_array_t *colors;
	OVERRIDE_COLORS("BodyColors", bodyColors);
	OVERRIDE_COLORS("BodyBgs", bodyBgs);
	OVERRIDE_COLORS("BorderColors", borderColors);

	OVERRIDE_FONT_FAMILY("HeadingFontFamily", bsHeadingFont);
	OVERRIDE_FONT_SIZE("HeadingFontSize", bsHeadingFont);
	OVERRIDE_FONT_WEIGHT("HeadingFontWeight", bsHeadingFont);
	OVERRIDE_COLORS("HeadingColors", headingColors);
	toml_array_t *size;
	OVERRIDE_HX_FONT_SIZE("H1FontSize", h1FontSize);
	OVERRIDE_HX_FONT_SIZE("H2FontSize", h2FontSize);
	OVERRIDE_HX_FONT_SIZE("H3FontSize", h3FontSize);
	OVERRIDE_HX_FONT_SIZE("H4FontSize", h4FontSize);
	OVERRIDE_HX_FONT_SIZE("H5FontSize", h5FontSize);
	OVERRIDE_HX_FONT_SIZE("H6FontSize", h6FontSize);
	OVERRIDE_COLORS("CardBgs", cardBgs);

	toml_free(toml);

	QObject *ancestor;
	QObject *grandAncestor = parent->parent();
	while ((ancestor = grandAncestor))
		if (!(grandAncestor = ancestor->parent()))
			for (auto child : ancestor->findChildren<QObject *>())
				if (!strcmp(child->metaObject()->className(),
							"Bootstrap")) {
					bsMode = qobject_cast<Bootstrap *>
						(child)->mode();
					break;
				}
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
	emit headingColorChanged();
	emit cardBgChanged();
	for (auto sibling : parent()->findChildren<QObject *>())
		if (strstr(sibling->metaObject()->className(), "_QMLTYPE_"))
			for (auto child : sibling->children())
				if (!strcmp(child->metaObject()->className(),
							"Bootstrap"))
					qobject_cast<Bootstrap *>(child)
						->setMode(mode);
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

QString Bootstrap::fontSansSerif() const
{
	return bsFontSansSerif;
}

QFont Bootstrap::bodyFont() const
{
	return bsBodyFont;
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

int Bootstrap::heading() const
{
	return htmlHeading;
}

void Bootstrap::setHeading(int heading)
{
	if (heading == htmlHeading) return;
	htmlHeading = heading;
	emit headingChanged();
	bsHeadingFont.setPointSizeF(headingFontSize());
	emit headingFontChanged();
}

QFont Bootstrap::headingFont() const
{
	return bsHeadingFont;
}

qreal Bootstrap::headingFontSize(const qreal parentWidth)
{
	switch (htmlHeading) {
		case 1:
			return h1FontSize[0] + h1FontSize[1] * parentWidth;
		case 2:
			return h2FontSize[0] + h2FontSize[1] * parentWidth;
		case 3:
			return h3FontSize[0] + h3FontSize[1] * parentWidth;
		case 4:
			return h4FontSize[0] + h4FontSize[1] * parentWidth;
		case 5:
			return h5FontSize[0] + h5FontSize[1] * parentWidth;
		default:
			return h6FontSize[0] + h6FontSize[1] * parentWidth;
	}
}

QColor Bootstrap::headingColor() const
{
	return headingColors.at(static_cast<int>(bsMode));
}

QColor Bootstrap::cardBg() const
{
	return cardBgs.at(static_cast<int>(bsMode));
}
