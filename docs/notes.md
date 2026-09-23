# Git NOTES
1) branch ie. git switch -c docs/rmc-notes (specific to the RMC notes branch)
2) confirm changes are there ie. git status
3) stage it ie. git add docs/notes.md
4) commit it ie. git commit -m "message"
5) push it ie. git push -u origin docs/rmc-notes
6) Open given link, approve pull request and merge
7) Sync Main ie. git switch main
8) Pull ie. git pull





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


# NMEA RMC Setence Notes

Example: `$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A`

| Field | Value | Meaning |
|---|---|---|
| Header | `$GPRMC` | `$` starts the sentence. `GP` = talker ID (GPS receiver). `RMC` = sentence type: Recommended min navigation information|
| 1 | `123519` | UTC time, `hhmmss` → 12:35:19 UTC. |
| 2 | `A` | Status: `A` = data valid (active fix), `V` = warning/no valid fix. |
| 3 | `4807.038` | Latitude, `ddmm.mmmm` format. |
| 4 | `N` | Hemisphere for latitude: North. |
| 5 | `01131.000` | Longitude, `dddmm.mmmm` format. |
| 6 | `E` | Hemisphere for longitude: East. |
| 7 | `022.4` | Speed over ground, in knots. |
| 8 | `084.4` | Course/track made good, in degrees, referenced to true north. |
| 9 | `230394` | Date, `ddmmyy` → 23 March 1994. |
| 10 | `003.1` | Magnetic variation — how far magnetic north differs from true north, in degrees. |
| 11 | `W` | Direction of that variation: West. |
| Checksum | `*6A` | XOR of every character between `$` and `*`, same mechanism as GGA. |

**Notes:**
- Lat/lon shift to fields 3-6 here (vs. 2-5 in GGA), because the status flag at field 2 pushes everything over by one.
- Date is `ddmmyy`, not `mmddyy` — easy to misread against US convention.
- Speed is in knots, not mph/km/h — a conversion to add if the parser needs SI units downstream.