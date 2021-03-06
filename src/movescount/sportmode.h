#ifndef CUSTOMMODE_H
#define CUSTOMMODE_H

#include <QObject>
#include <QVariantMap>
#include <QMap>
#include <QList>

#include "libambit.h"

QMap<int, int> qmapInit();
static const QMap<int, int> movescount2ambitConverter = qmapInit();

class CustomModeDisplay : public QObject
{
    Q_OBJECT
public:
    explicit CustomModeDisplay(QVariantMap &displayMap, QObject *parent = 0);
    CustomModeDisplay(const CustomModeDisplay &other);

    CustomModeDisplay& operator=(const CustomModeDisplay &rhs);

    void toAmbitCustomModeData(ambit_sport_mode_display_t *ambitDisplay);

private:
    u_int16_t ambitDisplayType();
    void toAmbitBarographDisplay(ambit_sport_mode_display_t *ambitDisplay);
    void toAmbitLinegraphDisplay(ambit_sport_mode_display_t *ambitDisplay);
    void toAmbitTextDisplay(ambit_sport_mode_display_t *ambitDisplay);

    bool requiresHRBelt;
    int row1;
    int row2;
    int type;
    QList<int> views;


    static const QString REQUIRES_HR_BELT;
    static const QString ROW_1;
    static const QString ROW_2;
    static const QString TYPE;
    static const QString VIEWS;

    static const int AMBIT_SINGLE_ROW_DISPLAY_TYPE = 0x0106;
    static const int AMBIT_DOUBLE_ROWS_DISPLAY_TYPE = 0x0105;
    static const int AMBIT_TRIPLE_ROW_DISPLAY_TYPE = 0x0104;
    static const int AMBIT_GRAPH_DISPLAY_TYPE = 0x0101;

    static const int MOVESCOUNT_SINGLE_ROW_DISPLAY_TYPE = 4;
    static const int MOVESCOUNT_DOUBLE_ROWS_DISPLAY_TYPE = 6;
    static const int MOVESCOUNT_TRIPLE_ROW_DISPLAY_TYPE = 5;
    static const int MOVESCOUNT_LINEGRAPH_DISPLAY_TYPE = 1;
    static const int MOVESCOUNT_BAROGRAPH_DISPLAY_TYPE = 8;
};

class CustomMode : public QObject
{
    Q_OBJECT
public:
    explicit CustomMode(QVariantMap &customModeMap, QObject *parent = 0);
    CustomMode(const CustomMode &other);

    CustomMode& operator=(const CustomMode &rhs);

    uint getCustomModeId() const;

    void toAmbitCustomModeData(ambit_sport_mode_t *ambitCustomMode, ambit_sport_mode_device_settings_t *ambitSettings);
    void toAmbitSettings(ambit_sport_mode_settings_t *settings);
    void toAmbitName(char ambitName[]);

signals:

public slots:

private:
    u_int16_t hrbeltAndPods();

    uint activityId;
    uint altiBaroMode;
//    uint autoPause;
    uint autolapDistance;
    uint gpsInterval;
    uint hrLimitHigh;
    uint hrLimitLow;
    uint interval1distance;
    uint interval2distance;
    uint interval1time;
    uint interval2time;
    uint intervalRepetitions;
    QString activityName;
    uint recordingInterval;
//    uint tonesMode;
    bool useAccelerometer;
    bool useAutolap;
//    bool useAutomaticLogRecording;
    bool useBikePod;
    bool useCadencePod;
    bool useFootPod;
    bool usePowerPod;
    bool useHrBelt;
    bool useHrLimits;
    bool useIntervals;
    uint sportmodeId;
    uint autoScrolingSpeed;
    float autoPauseSpeed;
    uint backlightMode;
    uint displayIsNegative;
    uint showNavigationSelection;
    QList<CustomModeDisplay> displays;
    QList<uint> appRuleIds;
    QList<uint> loggedAppRuleIds;

public:
    static const QString ACTIVITY_ID;
    static const QString ALTI_BARO_MODE;
    static const QString AUTOLAP_DISTANCE;
    static const QString GPS_INTERVAL;
    static const QString HR_LIMIT_HIGH;
    static const QString HR_LIMIT_LOW;
    static const QString INTERVAL_1_DISTANCE;
    static const QString INTERVAL_2_DISTANCE;
    static const QString INTERVAL_1_TIME;
    static const QString INTERVAL_2_TIME;
    static const QString INTERVAL_REPETITIONS;
    static const QString ACTIVITY_NAME;
    static const QString RECORDING_INTERVAL;
    static const QString USE_ACCELEROMETER;
    static const QString USE_AUTOLAP;
    static const QString USE_BIKE_POD;
    static const QString USE_CADENS_POD;
    static const QString USE_FOOT_POD;
    static const QString USE_POWER_POD;
    static const QString USE_HR_BELT;
    static const QString USE_HR_LIMITS;
    static const QString USE_INTERVALS;
    static const QString SPORT_MODE_ID;
    static const QString AUTO_SCROLING_SPEED;
    static const QString AUTO_PAUSE_SPEED;
    static const QString BACKLIGHT_MODE;
    static const QString DISPLAY_IS_NEGATIVE;
    static const QString SHOW_NAVIGATION_SELECTION;
    static const QString DISPLAY;
    static const QString DISPLAYED_RULE_IDS;
    static const QString LOGGED_RULE_IDS;

    static const int NAME_SIZE = 16;
};

#endif // CUSTOMMODE_H
