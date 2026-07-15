# C-Wire

**C-Wire** is a high-performance data processing tool designed to synthesize and analyze electrical distribution grids. It combines optimized Shell scripting for data pipelines with a core engine written in C that leverages self-balancing **AVL Trees** to perform fast sorting, capacity checks, and consumption analysis on large datasets.

## Features
- **Efficient Data Pipeline:** Automated filtering, cleaning, and preprocessing of raw data via a centralized Shell script.
- **Advanced Data Structures:** Employs AVL Trees in C to guarantee $O(\log n)$ algorithmic complexity for search, insertion, and balancing operations.
- **Automated Visualization:** Formats analytical results and auto-generates clean graphical representations using Gnuplot.
- **Software Engineering Standards:** Managed via a structural `Makefile` with precise memory allocation control and robust error handling.

---

## Prerequisites & Installation

Before running the application, make sure `gnuplot` is installed on your system for graph generation. On Debian/Ubuntu-based distributions, install it using:

```bash
sudo apt update && sudo apt install gnuplot
```
Ensure that all project source files (.c and .h templates) and the Makefile are located in the build directory, and that your target dataset is placed in the input/ folder.

## Usage

1. Navigate to the project root folder:

```bash
  cd C-Wire
```

2. Execute the master controller Shell script using the following syntax:

```bash
  ./c-wire.sh input/[filename] [station_type] [consumer_type]
```

### Arguments References

| Argument | Allowed Values | Description |
| :--- | :--- | :--- |
| `input/[filename]` | Path to your CSV file | The raw source dataset to process (e.g., `input/data.csv`). |
| `[station_type]` | `hvb`, `hva`, `lv` | Substation type to target: High Voltage B, High Voltage A, or Low Voltage. |
| `[consumer_type]` | `comp`, `indiv`, `all` | Filter by consumer segment: Companies (`comp`), Individuals (`indiv`), or Both (`all`). |

**Note:** Certain combinations are forbidden (e.g., individual consumers are not connected directly to hvb or hva substations).

## Utility Commands

### Help Menu

To display configuration options, system rules, and valid parameter combinations, use the help option:

```bash
  ./c-wire.sh -h
```

### Clean Workspace
To remove binaries, intermediate object files (.o), and temporary logs, run:
```bash
  ./c-wire.sh clean
```

### Troubleshooting Permissions
If you encounter a Permission Denied error when executing the script, grant executable rights recursively to the directory using:
```bash
  chmod -R u+x .
```

## Developers

- [@ismankt](https://www.github.com/ismankt)
- [@Mohamine2](https://www.github.com/Mohamine2)
- [@satyalexis](https://www.github.com/satyalexis)
