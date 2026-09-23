# NMEA GGA Sentence Notes

Example: `$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47`

| Field | Value | Meaning |
|---|---|---|
| Header | GPGGA | ... |
| 1 | 123519 | ... |

Order of CheckSum:
1) Translate RAW --> ASCII
2) ASCII --> BINARY
3) BINARY XOR Combination
4) Final value == 47? (Hex) 
5) If yes then transmission successful 