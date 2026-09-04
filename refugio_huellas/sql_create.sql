PRAGMA foreign_keys = ON;

CREATE TABLE IF NOT EXISTS empleados (
telefono TEXT NOT NULL,
correo TEXT NOT NULL,
sueldo REAL NOT NULL,
nombre TEXT NOT NULL,
apellido TEXT NOT NULL,
turno TEXT NOT NULL CHECK (turno IN ('MATUTINO', 'VESPERTINO'),
PRIMARY KEY (telefono, correo)
);

CREATE TABLE IF NOT EXISTS perros (
id INTEGER PRIMARY KEY AUTOINCREMENT,
nombre TEXT NOT NULL,
edad INTEGER,
raza TEXT,
diagnostico TEXT,
estado TEXT NOT NULL CHECK (estado IN ('ADOPTADO', 'NO ADOPTADO'),
telefono TEXT,
correo TEXT,
FOREIGN KEY (telefono, coreeo) REFERENCES empleados (telefono, correo)
ON UPDATE CASCADE
ON DELETE CASCADE
);

CREATE TABLE gatos (
id INTEGER PRIMARY KEY AUTOINCREMENT,
nombre TEXT NOT NULL,
edad INTEGER,
test TEXT, 
indoor INTEGER CHECK (indoor IN (0, 1)),
diagnostico TEXT,
estado TEXT NOT NULL CHECK (estado IN ('ADOPTADO', 'NO ADOPTADO')),
telefono TEXT,
correo TEXT,
FOREIGN KEY (telefono, correo) REFERENCES empleados (telefono, correo) 
ON UPDATE CASCADE
ON DELETE CASCADE
)

CREATE TABLE IF NOT EXISTS direcciones(
id INTEGER PRIMARY KEY AUTOINCREMENT,
calle TEXT,
estado TEXT,
pais TEXT,
numero TEXT
);

CREATE TABLE IF NOT EXISTS candidatos (
telefono TEXT NOT NULL,
correo TEXT NOT NULL,
mascotas TEXT,
nombre TEXT NOT NULL,
apellido TEXT NOT NULL,
direccion_id INTEGER  NOT NULL,
PRIMARY KEY (telefono,correo),
FOREIGN KEY (direccion_id) REFERENCES direcciones (id)
);
