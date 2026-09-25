# Git NOTES
1) branch ie. git switch -c docs/rmc-notes (specific to the RMC notes branch)
2) confirm changes are there ie. git status
3) stage it ie. git add docs/notes.md
4) commit it ie. git commit -m "message"
5) push it ie. git push -u origin docs/rmc-notes
6) Open given link, approve pull request and merge
7) Sync Main ie. git switch main
8) Pull ie. git pull

# Parser Requirements 
The parser shall validate the checksum of every sentence before extracting field data.
The parser shall reject sentences with an invalid checksum without crashing.
The parser shall decode GGA sentences into latitude, longitude, altitude, fix quality, and satellite count.
The parser shall convert coordinate fields from degrees-minutes format to decimal degrees.

## NMEA 4.11 System ID and Signal ID Reference

| GNSS System | System ID | Satellite ID | Signal ID | Signal / Channel |
|---|---|---|---|---|
| GPS | 1 (GP) | 1 - 32 GPS, 33 - 64 GPS SBAS | 0 | All signals |
| | | | 1 | L1 C/A |
| | | | 2 | L1 P(Y) |
| | | | 3 | L1 M |
| | | | 4 | L2 P(Y) |
| | | | 5 | L2C-M |
| | | | 6 | L2C-L |
| | | | 7 | L5-I |
| | | | 8 | L5-Q |
| | | | 9 - F | Reserved |
| GLONASS | 2 (GL) | 1 - 99, 33 - 64 SBAS, 65 - 99 GL | 0 | All signals |
| | | | 1 | L1 C/A |
| | | | 2 | L1 P |
| | | | 3 | L2 C/A |
| | | | 4 | L2 P |
| | | | 5 - 16 | Reserved |
| Galileo | 3 (GA) | 1 - 36 GA, 37 - 64 GA SBAS | 0 | All signals |
| | | | 1 | E5a |
| | | | 2 | E5b |
| | | | 3 | E5a+b |
| | | | 4 | E6-A |
| | | | 5 | E6-BC |
| | | | 6 | L1-A |
| | | | 7 | L1-BC |
| | | | 8 - 16 | Reserved |
| BDS (BeiDou System) | 4 (GB/BD) | 1 - 64 BD | 0 | All signals |
| | | | 1 | B1I |
| | | | 2 | B1Q |
| | | | 3 | B1C |
| | | | 4 | B1A |
| | | | 5 | B2-a |
| | | | 6 | B2-b |
| | | | 7 | B2 a+b |
| | | | 8 | B3I |
| | | | 9 | B3Q |
| | | | 10 | B3A |
| | | | 11 | B2I |
| | | | 12 | B2Q |
| | | | 13 - 16 | Reserved |
| QZSS | 5 (GQ) | 1 - 10 QZ, 55 - 63 QZ SBAS | 0 | All signals |
| | | | 1 | L1 C/A |
| | | | 2 | L1C (D) |
| | | | 3 | L1C (P) |
| | | | 4 | L1S |
| | | | 5 | L2C-M |
| | | | 6 | L2C-L |
| | | | 7 | L5-I |
| | | | 8 | L5-Q |
| | | | 9 | L6D |
| | | | 10 | L6E |
| | | | 11 - 16 | Reserved |
| NavIC | 6 (GI) | 1 - 15 GI, 33 - 64 SBAS | 0 | All signals |
| | | | 1 | L5-SPS |
| | | | 2 | S-SPS |
| | | | 3 | L5-RS |
| | | | 4 | S-RS |
| | | | 5 | L1-SPS |
| | | | 6 - F | Reserved |



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