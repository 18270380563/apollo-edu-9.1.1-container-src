import React, { useCallback, useEffect, useState } from 'react';
import { message } from '@dreamview/dreamview-ui';
import useWebSocketServices from '@dreamview/dreamview-core/src/services/hooks/useWebSocketServices';
import { usePickHmiStore } from '@dreamview/dreamview-core/src/store/HmiStore';
import Logger from '@dreamview/log';
import { PlayRTKRecordStatus } from '../../util';
import { DynamicEffectButtonMemo, DynamicEffectButtonStatus } from '../../DynamicEffectButton';
import { StreamDataNames } from '../../../../services/api/types';
import useStyle from './useStyle';
import { DisengageType } from '../../../panels/DashBoard';

const logger = Logger.getInstance('PlayerControlBar');

function WayFollowBtn() {
    const [hmi] = usePickHmiStore();
    const { classes } = useStyle();
    const [simData, setSimData] = useState<any>({});
    const { mainApi, isMainConnected, streamApi } = useWebSocketServices();

    const handleStartWayFollow = useCallback(() => {
        if (!isMainConnected) {
            return;
        }
        mainApi
            .startPlayRTKRecorder()
            .then(() => {
                logger.debug('start play rtkRecorder');
            })
            .catch((err) => {
                message({ type: 'error', content: err.data.info.message });
            });
    }, [mainApi, isMainConnected]);

    const btnStatus = (() => {
        if ((hmi?.globalComponents.RTKPlayer.processStatus.status as unknown) === PlayRTKRecordStatus.FATAL) {
            return DynamicEffectButtonStatus.START;
        }
        if ((hmi?.globalComponents.RTKPlayer.processStatus.status as unknown) === PlayRTKRecordStatus.OK) {
            return DynamicEffectButtonStatus.RUNNING;
        }
        return DynamicEffectButtonStatus.DISABLE;
    })();

    const handleStopWayFollow = () => {
        mainApi.StopPlayRtkRecorder().catch((err) => {
            message({ type: 'error', content: err.data.info.message });
        });
    };

    useEffect(() => {
        const unsubscribe = streamApi.subscribeToData(StreamDataNames.SIM_WORLD).subscribe((data) => {
            setSimData(data);
        });
        return () => {
            unsubscribe.unsubscribe();
        };
    }, []);

    const hasStopBtn =
        btnStatus === DynamicEffectButtonStatus.RUNNING &&
        simData?.autoDrivingCar?.disengageType === DisengageType.DISENGAGE_NONE;

    return (
        <div id='guide-auto-drive-bar' className={classes['ic-play-container']}>
            <DynamicEffectButtonMemo
                behavior={{
                    [DynamicEffectButtonStatus.START]: {
                        text: 'START',
                        clickHandler: handleStartWayFollow,
                    },
                    [DynamicEffectButtonStatus.RUNNING]: {
                        text: 'RUNNING',
                    },
                    [DynamicEffectButtonStatus.DISABLE]: {
                        disabledMsg: 'Please record the trajectory first, and select the corresponding record.',
                        text: 'START',
                    },
                }}
                status={btnStatus}
            />
            {hasStopBtn && (
                <>
                    &nbsp;&nbsp;
                    <DynamicEffectButtonMemo
                        behavior={{
                            [DynamicEffectButtonStatus.STOP]: {
                                text: 'STOP',
                                clickHandler: handleStopWayFollow,
                            },
                        }}
                        status={DynamicEffectButtonStatus.STOP}
                    />
                </>
            )}
        </div>
    );
}

export const WayFollowBtnMemo = React.memo(WayFollowBtn);
