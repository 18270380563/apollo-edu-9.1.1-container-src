import { useMakeStyle } from '@dreamview/dreamview-theme';

export default function useStyle() {
    const hoc = useMakeStyle(() => ({
        'ic-play-container': {
            height: '40px',
            display: 'flex',
            justifyContent: 'center',
            alignItems: 'center',
        },
    }));

    return hoc();
}
