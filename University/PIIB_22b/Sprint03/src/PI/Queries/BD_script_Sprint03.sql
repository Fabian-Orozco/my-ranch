use Wumpus_PROD

----------------------------------------------------
-- tablas
----------------------------------------------------

/****** Object:  Table [dbo].[__EFMigrationsHistory]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[__EFMigrationsHistory](
	[MigrationId] [nvarchar](150) NOT NULL,
	[ProductVersion] [nvarchar](32) NOT NULL,
 CONSTRAINT [PK___EFMigrationsHistory] PRIMARY KEY CLUSTERED 
(
	[MigrationId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[AJUSTES_GASTOFIJO]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AJUSTES_GASTOFIJO](
	[correoUsuario] [varchar](50) NOT NULL,
	[nombre] [varchar](100) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[correoUsuario] ASC,
	[nombre] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[AJUSTES_USUARIO]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AJUSTES_USUARIO](
	[correoUsuario] [varchar](50) NOT NULL,
	[nombre] [varchar](100) NULL,
	[apellido1] [varchar](100) NULL,
	[apellido2] [varchar](100) NULL,
	[contrasenya] [varchar](100) NULL,
PRIMARY KEY CLUSTERED 
(
	[correoUsuario] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ANALISIS]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ANALISIS](
	[fechaCreacion] [datetime] NOT NULL,
	[direccion] [varchar](512) NULL,
	[fechaDescarga] [datetime] NULL,
	[gananciaMensual] [decimal](18, 2) NULL,
	[idNegocio] [int] NOT NULL,
	[estadoAnalisis] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[fechaCreacion] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[AspNetRoleClaims]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetRoleClaims](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[RoleId] [nvarchar](450) NOT NULL,
	[ClaimType] [nvarchar](max) NULL,
	[ClaimValue] [nvarchar](max) NULL,
 CONSTRAINT [PK_AspNetRoleClaims] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[AspNetRoles]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetRoles](
	[Id] [nvarchar](450) NOT NULL,
	[Name] [nvarchar](256) NULL,
	[NormalizedName] [nvarchar](256) NULL,
	[ConcurrencyStamp] [nvarchar](max) NULL,
 CONSTRAINT [PK_AspNetRoles] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[AspNetUserClaims]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetUserClaims](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[UserId] [nvarchar](450) NOT NULL,
	[ClaimType] [nvarchar](max) NULL,
	[ClaimValue] [nvarchar](max) NULL,
 CONSTRAINT [PK_AspNetUserClaims] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[AspNetUserLogins]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetUserLogins](
	[LoginProvider] [nvarchar](128) NOT NULL,
	[ProviderKey] [nvarchar](128) NOT NULL,
	[ProviderDisplayName] [nvarchar](max) NULL,
	[UserId] [nvarchar](450) NOT NULL,
 CONSTRAINT [PK_AspNetUserLogins] PRIMARY KEY CLUSTERED 
(
	[LoginProvider] ASC,
	[ProviderKey] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[AspNetUserRoles]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetUserRoles](
	[UserId] [nvarchar](450) NOT NULL,
	[RoleId] [nvarchar](450) NOT NULL,
 CONSTRAINT [PK_AspNetUserRoles] PRIMARY KEY CLUSTERED 
(
	[UserId] ASC,
	[RoleId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[AspNetUsers]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetUsers](
	[Id] [nvarchar](450) NOT NULL,
	[UserName] [nvarchar](256) NULL,
	[NormalizedUserName] [nvarchar](256) NULL,
	[Email] [nvarchar](256) NULL,
	[NormalizedEmail] [nvarchar](256) NULL,
	[EmailConfirmed] [bit] NOT NULL,
	[PasswordHash] [nvarchar](max) NULL,
	[SecurityStamp] [nvarchar](max) NULL,
	[ConcurrencyStamp] [nvarchar](max) NULL,
	[PhoneNumber] [nvarchar](max) NULL,
	[PhoneNumberConfirmed] [bit] NOT NULL,
	[TwoFactorEnabled] [bit] NOT NULL,
	[LockoutEnd] [datetimeoffset](7) NULL,
	[LockoutEnabled] [bit] NOT NULL,
	[AccessFailedCount] [int] NOT NULL,
 CONSTRAINT [PK_AspNetUsers] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[AspNetUserTokens]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetUserTokens](
	[UserId] [nvarchar](450) NOT NULL,
	[LoginProvider] [nvarchar](128) NOT NULL,
	[Name] [nvarchar](128) NOT NULL,
	[Value] [nvarchar](max) NULL,
 CONSTRAINT [PK_AspNetUserTokens] PRIMARY KEY CLUSTERED 
(
	[UserId] ASC,
	[LoginProvider] ASC,
	[Name] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[COMPONENTE]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[COMPONENTE](
	[nombreComponente] [varchar](30) NOT NULL,
	[nombreProducto] [varchar](30) NOT NULL,
	[fechaAnalisis] [datetime] NOT NULL,
	[monto] [decimal](18, 2) NULL,
	[cantidad] [decimal](18, 2) NULL,
	[unidad] [varchar](30) NULL,
PRIMARY KEY CLUSTERED 
(
	[nombreComponente] ASC,
	[nombreProducto] ASC,
	[fechaAnalisis] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[CONFIGURACION]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CONFIGURACION](
	[fechaAnalisis] [datetime] NOT NULL,
	[tipoNegocio] [int] NOT NULL,
	[porcentajeSS] [decimal](5, 2) NULL,
	[porcentajePL] [decimal](5, 2) NULL,
PRIMARY KEY CLUSTERED 
(
	[fechaAnalisis] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[EGRESO]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[EGRESO](
	[mes] [varchar](10) NOT NULL,
	[fechaAnalisis] [datetime] NOT NULL,
	[tipo] [varchar](10) NOT NULL,
	[monto] [decimal](18, 2) NOT NULL,
 CONSTRAINT [PK_Egreso] PRIMARY KEY CLUSTERED 
(
	[mes] ASC,
	[fechaAnalisis] ASC,
	[tipo] ASC,
	[monto] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ES_EMPLEADO_DE]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ES_EMPLEADO_DE](
	[nombreEmpleado] [varchar](30) NOT NULL,
	[fechaEmpleado] [datetime] NOT NULL,
	[nombreJefe] [varchar](30) NOT NULL,
	[fechaJefe] [datetime] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[nombreEmpleado] ASC,
	[fechaEmpleado] ASC,
	[nombreJefe] ASC,
	[fechaJefe] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[GASTO_FIJO]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GASTO_FIJO](
	[nombre] [varchar](30) NOT NULL,
	[fechaAnalisis] [datetime] NOT NULL,
	[monto] [decimal](18, 2) NULL,
	[orden] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[orden] ASC,
	[nombre] ASC,
	[fechaAnalisis] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[INGRESO]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[INGRESO](
	[mes] [varchar](10) NOT NULL,
	[fechaAnalisis] [datetime] NOT NULL,
	[tipo] [varchar](10) NOT NULL,
	[monto] [decimal](18, 2) NOT NULL,
 CONSTRAINT [PK_Ingreso] PRIMARY KEY CLUSTERED 
(
	[mes] ASC,
	[fechaAnalisis] ASC,
	[tipo] ASC,
	[monto] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[INVERSION_INICIAL]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[INVERSION_INICIAL](
	[fechaAnalisis] [datetime] NOT NULL,
	[nombre] [varchar](30) NOT NULL,
	[valor] [decimal](18, 2) NULL,
PRIMARY KEY CLUSTERED 
(
	[fechaAnalisis] ASC,
	[nombre] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[MES]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MES](
	[nombre] [varchar](10) NOT NULL,
	[fechaAnalisis] [datetime] NOT NULL,
	[inversionPorMes] [decimal](18, 2) NULL,
PRIMARY KEY CLUSTERED 
(
	[nombre] ASC,
	[fechaAnalisis] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[NEGOCIO]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[NEGOCIO](
	[id] [int] NOT NULL,
	[nombre] [varchar](30) NULL,
	[FechaCreacion] [datetime] NULL,
	[idUsuario] [nvarchar](450) NULL,
PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PRODUCTO]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PRODUCTO](
	[nombre] [varchar](30) NOT NULL,
	[fechaAnalisis] [datetime] NOT NULL,
	[lote] [int] NULL,
	[porcentajeDeVentas] [decimal](18, 2) NULL,
	[precio] [decimal](18, 2) NULL,
	[costoVariable] [decimal](18, 2) NOT NULL,
	[comisionDeVentas] [decimal](18, 2) NULL,
PRIMARY KEY CLUSTERED 
(
	[nombre] ASC,
	[fechaAnalisis] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PUESTO]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PUESTO](
	[nombre] [varchar](30) NOT NULL,
	[fechaAnalisis] [datetime] NOT NULL,
	[cantidadPlazas] [int] NULL,
	[salarioBruto] [decimal](18, 2) NULL,
	[orden] [bigint] IDENTITY(1,1) NOT NULL,
	[beneficios] [decimal](18, 2) NULL,
PRIMARY KEY CLUSTERED 
(
	[nombre] ASC,
	[fechaAnalisis] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_AspNetRoleClaims_RoleId]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE NONCLUSTERED INDEX [IX_AspNetRoleClaims_RoleId] ON [dbo].[AspNetRoleClaims]
(
	[RoleId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [RoleNameIndex]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE UNIQUE NONCLUSTERED INDEX [RoleNameIndex] ON [dbo].[AspNetRoles]
(
	[NormalizedName] ASC
)
WHERE ([NormalizedName] IS NOT NULL)
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_AspNetUserClaims_UserId]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE NONCLUSTERED INDEX [IX_AspNetUserClaims_UserId] ON [dbo].[AspNetUserClaims]
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_AspNetUserLogins_UserId]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE NONCLUSTERED INDEX [IX_AspNetUserLogins_UserId] ON [dbo].[AspNetUserLogins]
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_AspNetUserRoles_RoleId]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE NONCLUSTERED INDEX [IX_AspNetUserRoles_RoleId] ON [dbo].[AspNetUserRoles]
(
	[RoleId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [EmailIndex]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE NONCLUSTERED INDEX [EmailIndex] ON [dbo].[AspNetUsers]
(
	[NormalizedEmail] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [UserNameIndex]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE UNIQUE NONCLUSTERED INDEX [UserNameIndex] ON [dbo].[AspNetUsers]
(
	[NormalizedUserName] ASC
)
WHERE ([NormalizedUserName] IS NOT NULL)
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [index_componente_cantidad_]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE NONCLUSTERED INDEX [index_componente_cantidad_] ON [dbo].[COMPONENTE]
(
	[cantidad] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
/****** Object:  Index [id_negocio]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE NONCLUSTERED INDEX [id_negocio] ON [dbo].[NEGOCIO]
(
	[FechaCreacion] DESC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [Negocio_idUsuario]    Script Date: 28/11/2022 11:01:31 PM ******/
CREATE NONCLUSTERED INDEX [Negocio_idUsuario] ON [dbo].[NEGOCIO]
(
	[idUsuario] ASC
)
INCLUDE([FechaCreacion]) WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
ALTER TABLE [dbo].[ANALISIS] ADD  CONSTRAINT [Default_ganancia_mensual]  DEFAULT ((0)) FOR [gananciaMensual]
GO
ALTER TABLE [dbo].[ANALISIS] ADD  CONSTRAINT [DF_ANALISIS_estadoAnalisis]  DEFAULT ((1)) FOR [estadoAnalisis]
GO
ALTER TABLE [dbo].[CONFIGURACION] ADD  CONSTRAINT [DEFAULT_PORCENTAJSS]  DEFAULT ((0)) FOR [porcentajeSS]
GO
ALTER TABLE [dbo].[CONFIGURACION] ADD  CONSTRAINT [DEFAULT_PORCENTAJPL]  DEFAULT ((0)) FOR [porcentajePL]
GO
ALTER TABLE [dbo].[EGRESO] ADD  CONSTRAINT [df_monto_egreso]  DEFAULT ((0)) FOR [monto]
GO
ALTER TABLE [dbo].[INGRESO] ADD  CONSTRAINT [df_monto_ingreso]  DEFAULT ((0)) FOR [monto]
GO
ALTER TABLE [dbo].[MES] ADD  DEFAULT ((0.0)) FOR [inversionPorMes]
GO
ALTER TABLE [dbo].[PRODUCTO] ADD  CONSTRAINT [df_porcentajeVentas]  DEFAULT ((0)) FOR [porcentajeDeVentas]
GO
ALTER TABLE [dbo].[PRODUCTO] ADD  CONSTRAINT [df_precio]  DEFAULT ((0)) FOR [precio]
GO
ALTER TABLE [dbo].[PRODUCTO] ADD  CONSTRAINT [default_costoVariable]  DEFAULT ((0.0)) FOR [costoVariable]
GO
ALTER TABLE [dbo].[PRODUCTO] ADD  CONSTRAINT [default_comision]  DEFAULT ((0.0)) FOR [comisionDeVentas]
GO
ALTER TABLE [dbo].[PUESTO] ADD  CONSTRAINT [default_beneficios]  DEFAULT ((0.0)) FOR [beneficios]
GO
ALTER TABLE [dbo].[AJUSTES_GASTOFIJO]  WITH CHECK ADD  CONSTRAINT [FK_correoUsuario_delete] FOREIGN KEY([correoUsuario])
REFERENCES [dbo].[AJUSTES_USUARIO] ([correoUsuario])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AJUSTES_GASTOFIJO] CHECK CONSTRAINT [FK_correoUsuario_delete]
GO
ALTER TABLE [dbo].[AJUSTES_GASTOFIJO]  WITH CHECK ADD  CONSTRAINT [FK_correoUsuario_update] FOREIGN KEY([correoUsuario])
REFERENCES [dbo].[AJUSTES_USUARIO] ([correoUsuario])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[AJUSTES_GASTOFIJO] CHECK CONSTRAINT [FK_correoUsuario_update]
GO
ALTER TABLE [dbo].[ANALISIS]  WITH CHECK ADD  CONSTRAINT [FK__ANALISIS__idNegocio] FOREIGN KEY([idNegocio])
REFERENCES [dbo].[NEGOCIO] ([id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[ANALISIS] CHECK CONSTRAINT [FK__ANALISIS__idNegocio]
GO
ALTER TABLE [dbo].[ANALISIS]  WITH CHECK ADD  CONSTRAINT [FK__ANALISIS__UPDATE__idNegocio] FOREIGN KEY([idNegocio])
REFERENCES [dbo].[NEGOCIO] ([id])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[ANALISIS] CHECK CONSTRAINT [FK__ANALISIS__UPDATE__idNegocio]
GO
ALTER TABLE [dbo].[AspNetRoleClaims]  WITH CHECK ADD  CONSTRAINT [FK_AspNetRoleClaims_AspNetRoles_RoleId] FOREIGN KEY([RoleId])
REFERENCES [dbo].[AspNetRoles] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetRoleClaims] CHECK CONSTRAINT [FK_AspNetRoleClaims_AspNetRoles_RoleId]
GO
ALTER TABLE [dbo].[AspNetUserClaims]  WITH CHECK ADD  CONSTRAINT [FK_AspNetUserClaims_AspNetUsers_UserId] FOREIGN KEY([UserId])
REFERENCES [dbo].[AspNetUsers] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetUserClaims] CHECK CONSTRAINT [FK_AspNetUserClaims_AspNetUsers_UserId]
GO
ALTER TABLE [dbo].[AspNetUserLogins]  WITH CHECK ADD  CONSTRAINT [FK_AspNetUserLogins_AspNetUsers_UserId] FOREIGN KEY([UserId])
REFERENCES [dbo].[AspNetUsers] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetUserLogins] CHECK CONSTRAINT [FK_AspNetUserLogins_AspNetUsers_UserId]
GO
ALTER TABLE [dbo].[AspNetUserRoles]  WITH CHECK ADD  CONSTRAINT [FK_AspNetUserRoles_AspNetRoles_RoleId] FOREIGN KEY([RoleId])
REFERENCES [dbo].[AspNetRoles] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetUserRoles] CHECK CONSTRAINT [FK_AspNetUserRoles_AspNetRoles_RoleId]
GO
ALTER TABLE [dbo].[AspNetUserRoles]  WITH CHECK ADD  CONSTRAINT [FK_AspNetUserRoles_AspNetUsers_UserId] FOREIGN KEY([UserId])
REFERENCES [dbo].[AspNetUsers] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetUserRoles] CHECK CONSTRAINT [FK_AspNetUserRoles_AspNetUsers_UserId]
GO
ALTER TABLE [dbo].[AspNetUserTokens]  WITH CHECK ADD  CONSTRAINT [FK_AspNetUserTokens_AspNetUsers_UserId] FOREIGN KEY([UserId])
REFERENCES [dbo].[AspNetUsers] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetUserTokens] CHECK CONSTRAINT [FK_AspNetUserTokens_AspNetUsers_UserId]
GO
ALTER TABLE [dbo].[COMPONENTE]  WITH CHECK ADD  CONSTRAINT [FK_ComponenteProducto] FOREIGN KEY([nombreProducto], [fechaAnalisis])
REFERENCES [dbo].[PRODUCTO] ([nombre], [fechaAnalisis])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[COMPONENTE] CHECK CONSTRAINT [FK_ComponenteProducto]
GO
ALTER TABLE [dbo].[COMPONENTE]  WITH CHECK ADD  CONSTRAINT [FK_ComponenteProducto_Update] FOREIGN KEY([nombreProducto], [fechaAnalisis])
REFERENCES [dbo].[PRODUCTO] ([nombre], [fechaAnalisis])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[COMPONENTE] CHECK CONSTRAINT [FK_ComponenteProducto_Update]
GO
ALTER TABLE [dbo].[CONFIGURACION]  WITH CHECK ADD  CONSTRAINT [FK_ANALISIS_DELETE] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[CONFIGURACION] CHECK CONSTRAINT [FK_ANALISIS_DELETE]
GO
ALTER TABLE [dbo].[EGRESO]  WITH CHECK ADD FOREIGN KEY([mes], [fechaAnalisis])
REFERENCES [dbo].[MES] ([nombre], [fechaAnalisis])
GO
ALTER TABLE [dbo].[EGRESO]  WITH CHECK ADD  CONSTRAINT [FK_EGRESO_FECHA_DELETE] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[EGRESO] CHECK CONSTRAINT [FK_EGRESO_FECHA_DELETE]
GO
ALTER TABLE [dbo].[EGRESO]  WITH CHECK ADD  CONSTRAINT [FK_EGRESO_FECHA_UPDATE] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[EGRESO] CHECK CONSTRAINT [FK_EGRESO_FECHA_UPDATE]
GO
ALTER TABLE [dbo].[ES_EMPLEADO_DE]  WITH CHECK ADD  CONSTRAINT [FK_EMPLEADO_JEFE] FOREIGN KEY([nombreJefe], [fechaJefe])
REFERENCES [dbo].[PUESTO] ([nombre], [fechaAnalisis])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[ES_EMPLEADO_DE] CHECK CONSTRAINT [FK_EMPLEADO_JEFE]
GO
ALTER TABLE [dbo].[ES_EMPLEADO_DE]  WITH CHECK ADD  CONSTRAINT [FK_EMPLEADO_JEFE_UPDATE] FOREIGN KEY([nombreJefe], [fechaJefe])
REFERENCES [dbo].[PUESTO] ([nombre], [fechaAnalisis])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[ES_EMPLEADO_DE] CHECK CONSTRAINT [FK_EMPLEADO_JEFE_UPDATE]
GO
ALTER TABLE [dbo].[GASTO_FIJO]  WITH CHECK ADD  CONSTRAINT [FK_GASTO_FECHA] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[GASTO_FIJO] CHECK CONSTRAINT [FK_GASTO_FECHA]
GO
ALTER TABLE [dbo].[GASTO_FIJO]  WITH CHECK ADD  CONSTRAINT [FK_GASTO_FECHA_DELETE] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[GASTO_FIJO] CHECK CONSTRAINT [FK_GASTO_FECHA_DELETE]
GO
ALTER TABLE [dbo].[INGRESO]  WITH CHECK ADD FOREIGN KEY([mes], [fechaAnalisis])
REFERENCES [dbo].[MES] ([nombre], [fechaAnalisis])
GO
ALTER TABLE [dbo].[INGRESO]  WITH CHECK ADD  CONSTRAINT [FK_INGRESO_DELETE] FOREIGN KEY([mes], [fechaAnalisis])
REFERENCES [dbo].[MES] ([nombre], [fechaAnalisis])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[INGRESO] CHECK CONSTRAINT [FK_INGRESO_DELETE]
GO
ALTER TABLE [dbo].[INGRESO]  WITH CHECK ADD  CONSTRAINT [FK_INGRESO_UPDATE] FOREIGN KEY([mes], [fechaAnalisis])
REFERENCES [dbo].[MES] ([nombre], [fechaAnalisis])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[INGRESO] CHECK CONSTRAINT [FK_INGRESO_UPDATE]
GO
ALTER TABLE [dbo].[INVERSION_INICIAL]  WITH CHECK ADD  CONSTRAINT [FK__INVERSION__FECHA] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[INVERSION_INICIAL] CHECK CONSTRAINT [FK__INVERSION__FECHA]
GO
ALTER TABLE [dbo].[INVERSION_INICIAL]  WITH CHECK ADD  CONSTRAINT [FK__INVERSION__FECHA__UPDATE] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[INVERSION_INICIAL] CHECK CONSTRAINT [FK__INVERSION__FECHA__UPDATE]
GO
ALTER TABLE [dbo].[MES]  WITH CHECK ADD  CONSTRAINT [FK_MES_FECHA] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[MES] CHECK CONSTRAINT [FK_MES_FECHA]
GO
ALTER TABLE [dbo].[MES]  WITH CHECK ADD  CONSTRAINT [FK_MES_FECHA_UPDATE] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[MES] CHECK CONSTRAINT [FK_MES_FECHA_UPDATE]
GO
ALTER TABLE [dbo].[NEGOCIO]  WITH CHECK ADD  CONSTRAINT [FK_AspNetUser_CorreoUsuario] FOREIGN KEY([idUsuario])
REFERENCES [dbo].[AspNetUsers] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[NEGOCIO] CHECK CONSTRAINT [FK_AspNetUser_CorreoUsuario]
GO
ALTER TABLE [dbo].[PRODUCTO]  WITH CHECK ADD  CONSTRAINT [FK__PRODUCTO__FECHA] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[PRODUCTO] CHECK CONSTRAINT [FK__PRODUCTO__FECHA]
GO
ALTER TABLE [dbo].[PRODUCTO]  WITH CHECK ADD  CONSTRAINT [FK__PRODUCTO__FECHA_DELETE] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[PRODUCTO] CHECK CONSTRAINT [FK__PRODUCTO__FECHA_DELETE]
GO
ALTER TABLE [dbo].[PRODUCTO]  WITH CHECK ADD FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
GO
ALTER TABLE [dbo].[PUESTO]  WITH CHECK ADD  CONSTRAINT [FK__PUESTO__FECHA__UPDATE] FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON UPDATE CASCADE
GO
ALTER TABLE [dbo].[PUESTO] CHECK CONSTRAINT [FK__PUESTO__FECHA__UPDATE]
GO
ALTER TABLE [dbo].[PUESTO]  WITH CHECK ADD FOREIGN KEY([fechaAnalisis])
REFERENCES [dbo].[ANALISIS] ([fechaCreacion])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[CONFIGURACION]  WITH CHECK ADD  CONSTRAINT [CK_CONFIGURACION_TN] CHECK  (([tipoNegocio]>=(0) AND [tipoNegocio]<=(1)))
GO
ALTER TABLE [dbo].[CONFIGURACION] CHECK CONSTRAINT [CK_CONFIGURACION_TN]

----------------------------------------------------
-- procedures
----------------------------------------------------

-- Wilmer Araya Rivas | B80538
GO
/****** Object:  StoredProcedure [dbo].[actualizarBeneficios]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[actualizarBeneficios](@fechaAnalisis DATETIME)
AS
BEGIN
	IF EXISTS (SELECT * FROM GASTO_FIJO G JOIN ANALISIS A on G.fechaAnalisis = A.fechaCreacion WHERE G.nombre = 'Beneficios de empleados' AND G.fechaAnalisis = @fechaAnalisis)
		UPDATE GASTO_FIJO 
		SET monto =  dbo.obtTotalBeneficios(@fechaAnalisis)
		WHERE GASTO_FIJO.nombre = 'Beneficios de empleados' AND GASTO_FIJO.fechaAnalisis = @fechaAnalisis 
	ELSE
		INSERT INTO GASTO_FIJO (nombre, fechaAnalisis, monto, orden) VALUES ('Beneficios de empleados', @fechaAnalisis, dbo.obtTotalBeneficios(@fechaAnalisis), 4)
END

-- Gabriel Bonilla Rivera | C01252
GO
/****** Object:  StoredProcedure [dbo].[ActualizarGananciaMensual]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[ActualizarGananciaMensual] @ganancia decimal, @fecha DateTime
AS
UPDATE ANALISIS 
SET gananciaMensual = @ganancia
WHERE ANALISIS.fechaCreacion = @fecha

-- Wilmer Araya Rivas | B80538
GO
/****** Object:  StoredProcedure [dbo].[actualizarGastoPrestaciones]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[actualizarGastoPrestaciones](@fechaAnalisis DATETIME, @porcentaje varchar(20))
AS
BEGIN
	SET @porcentaje = REPLACE(@porcentaje, ',', '.')
	IF EXISTS (SELECT * FROM GASTO_FIJO G JOIN ANALISIS A on G.fechaAnalisis = A.fechaCreacion WHERE G.nombre = 'Prestaciones laborales' AND G.fechaAnalisis = @fechaAnalisis)
		UPDATE GASTO_FIJO 
		SET monto =  dbo.obtGastoPrestaciones (@fechaAnalisis, dbo.convertTOdecimal (@porcentaje))
		WHERE GASTO_FIJO.nombre = 'Prestaciones laborales' AND GASTO_FIJO.fechaAnalisis = @fechaAnalisis 
	ELSE
		INSERT INTO GASTO_FIJO (nombre, fechaAnalisis, monto, orden) VALUES ('Prestaciones laborales', @fechaAnalisis, dbo.obtGastoPrestaciones (@fechaAnalisis, dbo.convertTOdecimal (@porcentaje)), 3)
END

-- Wilmer Araya Rivas | B80538
GO
/****** Object:  StoredProcedure [dbo].[actualizarGastoSeguroSocial]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[actualizarGastoSeguroSocial](@fechaAnalisis DATETIME, @porcentaje varchar(20))
AS
BEGIN
	SET @porcentaje = REPLACE(@porcentaje, ',', '.')
	IF EXISTS (SELECT * FROM GASTO_FIJO G JOIN ANALISIS A on G.fechaAnalisis = A.fechaCreacion WHERE G.nombre = 'Seguridad social' AND G.fechaAnalisis = @fechaAnalisis)
		UPDATE GASTO_FIJO 
		SET monto =  dbo.obtGastoSeguroSocial (@fechaAnalisis, dbo.convertTOdecimal (@porcentaje))
		WHERE GASTO_FIJO.nombre = 'Seguridad social' AND GASTO_FIJO.fechaAnalisis = @fechaAnalisis 
	ELSE
		INSERT INTO GASTO_FIJO VALUES ('Seguridad social', @fechaAnalisis, dbo.obtGastoSeguroSocial (@fechaAnalisis, dbo.convertTOdecimal (@porcentaje)), 2)
END

-- Wilmer Araya Rivas | B80538
GO
/****** Object:  StoredProcedure [dbo].[actualizarSalariosNeto]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[actualizarSalariosNeto](@fechaAnalisis DATETIME, @seguroSocial varchar(20), @prestaciones varchar(20))
AS
BEGIN
	SET @seguroSocial = REPLACE(@seguroSocial, ',', '.')
	SET @prestaciones = REPLACE(@prestaciones, ',', '.')
	IF EXISTS (SELECT * FROM GASTO_FIJO G JOIN ANALISIS A on G.fechaAnalisis = A.fechaCreacion WHERE G.nombre = 'Salarios netos' AND G.fechaAnalisis = @fechaAnalisis)
		UPDATE GASTO_FIJO 
		SET monto =  dbo.obtTotalSalariosNeto(@fechaAnalisis, dbo.convertTOdecimal (@seguroSocial), dbo.convertTOdecimal ( @prestaciones))
		WHERE GASTO_FIJO.nombre = 'Salarios netos' AND GASTO_FIJO.fechaAnalisis = @fechaAnalisis 
	ELSE
		INSERT INTO GASTO_FIJO VALUES ('Salarios netos', @fechaAnalisis, dbo.obtTotalSalariosNeto(@fechaAnalisis, dbo.convertTOdecimal (@seguroSocial), dbo.convertTOdecimal ( @prestaciones)), 1)
END

-- Christopher Perez Blanco | C05881
GO
/****** Object:  StoredProcedure [dbo].[AgregarComponente]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[AgregarComponente]
(@nombreComponente varchar(30), @nombreProducto varchar(30), @fechaAnalisis datetime, @monto decimal(18, 2),  @cantidad decimal(18, 2), @unidad varchar(30))
as
Begin
	insert into Componente values(@nombreComponente, @nombreProducto, @fechaAnalisis,@monto, @cantidad, @unidad)
End
GO
/****** Object:  StoredProcedure [dbo].[AgregarEgresoMes]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[AgregarEgresoMes] @fechaAnalisis datetime, @nombreMes varchar(10), @tipo bit, @monto decimal(18,2)
AS
	insert into EGRESO values (@nombreMes,@fechaAnalisis, @tipo, @monto);
GO
/****** Object:  StoredProcedure [dbo].[AgregarIngresoMes]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[AgregarIngresoMes] @fechaAnalisis datetime, @nombreMes varchar(10), @tipo bit, @monto decimal(18,2)
AS
	insert into INGRESO values (@nombreMes,@fechaAnalisis, @tipo, @monto);

-- Gabriel Bonilla Rivera | C01252
GO
/****** Object:  StoredProcedure [dbo].[borrar_beneficio]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[borrar_beneficio] @nombre varchar(30), @nombrePuesto varchar(30), @fechaAnalisis DateTime, @monto int, @plazas int
AS
DELETE FROM BENEFICIO WHERE nombre=@nombre and nombrePuesto=@nombrePuesto and fechaAnalisis=@fechaAnalisis and monto=@monto and cantidadPlazas=@plazas

-- Christopher Perez Blanco | C05881
GO
/****** Object:  StoredProcedure [dbo].[BorrarComponente]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create procedure [dbo].[BorrarComponente] 
(@nombreComponente varchar(30), @nombreProducto varchar(30), @fechaAnalisis datetime)
as
Begin
	Delete from COMPONENTE where COMPONENTE.nombreComponente=@nombreComponente and COMPONENTE.nombreProducto=@nombreProducto and COMPONENTE.fechaAnalisis=@fechaAnalisis
End
GO
/****** Object:  StoredProcedure [dbo].[BorrarNegocio]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE   procedure [dbo].[BorrarNegocio](
	@idNegocio int
)
as
begin 
	set transaction isolation level read committed
	begin transaction BorrarNegocio
	begin try
		DELETE FROM NEGOCIO WHERE id = @idNegocio
		commit transaction BorrarNegocio
	end try
	begin catch
		rollback transaction BorrarNegocio
	end catch
end

-- Gabriel Bonilla Rivera | C01252
GO
/****** Object:  StoredProcedure [dbo].[CostoVariablePorLoteComponente]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[CostoVariablePorLoteComponente] @nombreComponente varchar(30), @nombreProducto varchar(30), @fechaAnalisis datetime, @result decimal(18,2) output
AS
set @result = (select C.cantidad * C.monto
from Componente as C
where C.nombreComponente = @nombreComponente and C.nombreProducto = @nombreProducto and C.fechaAnalisis = @fechaAnalisis)

-- Gabriel Bonilla Rivera | C01252
GO
/****** Object:  StoredProcedure [dbo].[CostoVariablePorUnidadComponente]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[CostoVariablePorUnidadComponente] @nombreComponente varchar(30), @nombreProducto varchar(30), @fechaAnalisis datetime, @resultado decimal(18,2) output
AS
declare @lote int 
set @lote = (select lote from PRODUCTO as P where P.fechaAnalisis = @fechaAnalisis and P.nombre = @nombreProducto)
declare @CostoVarLoteComponente decimal(18,2)
exec CostoVariablePorLoteComponente @nombreComponente = @nombreComponente, @nombreProducto = @nombreProducto, @fechaAnalisis = @fechaAnalisis, @result = @CostoVarLoteComponente output
set @resultado = @CostoVarLoteComponente / @lote

-- Gabriel Bonilla Rivera | C01252
GO
/****** Object:  StoredProcedure [dbo].[CostoVariableTotal]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[CostoVariableTotal] @nombreProducto VARCHAR(30), @fechaAnalisis DATETIME
AS
declare @nomComponente varchar(30), @total decimal(18,2), @costoVarUnitario decimal(18,2)
set @total = 0
declare c1 cursor FOR
select C.nombreComponente from COMPONENTE AS C where c.nombreProducto = @nombreProducto AND C.fechaAnalisis = @fechaAnalisis
open c1
fetch next from c1 into @nomComponente
while @@FETCH_STATUS = 0
	begin
	exec CostoVariablePorUnidadComponente @nombreComponente = @nomComponente, @nombreProducto = @nombreProducto, @fechaAnalisis = @fechaAnalisis, @resultado = @costoVarUnitario output;
	set @total = @total + @costoVarUnitario
	Print @costoVarUnitario
	fetch next from c1 into @nomComponente
	end
close c1
deallocate c1

Update PRODUCTO
SET PRODUCTO.costoVariable = @total
WHERE producto.fechaAnalisis = @fechaAnalisis and producto.nombre = @nombreProducto
GO
/****** Object:  StoredProcedure [dbo].[crearEgresosPorMes]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[crearEgresosPorMes](@fechaAnalisis DATETIME)
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM EGRESO E JOIN MES M on E.fechaAnalisis = M.fechaAnalisis WHERE E.fechaAnalisis = @fechaAnalisis)
        INSERT INTO EGRESO(mes, fechaAnalisis, tipo)
        VALUES
            ('Mes 1', @fechaAnalisis, 'contado'), ('Mes 2', @fechaAnalisis, 'contado'), ('Mes 3', @fechaAnalisis, 'contado'),
            ('Mes 4', @fechaAnalisis, 'contado'), ('Mes 5', @fechaAnalisis, 'contado'), ('Mes 6', @fechaAnalisis, 'contado'),
            ('Mes 1', @fechaAnalisis, 'credito'), ('Mes 2', @fechaAnalisis, 'credito'), ('Mes 3', @fechaAnalisis, 'credito'),
            ('Mes 4', @fechaAnalisis, 'credito'), ('Mes 5', @fechaAnalisis, 'credito'), ('Mes 6', @fechaAnalisis, 'credito'),
            ('Mes 1', @fechaAnalisis, 'otros'), ('Mes 2', @fechaAnalisis, 'otros'), ('Mes 3', @fechaAnalisis, 'otros'),
            ('Mes 4', @fechaAnalisis, 'otros'), ('Mes 5', @fechaAnalisis, 'otros'), ('Mes 6', @fechaAnalisis, 'otros');
END
GO
/****** Object:  StoredProcedure [dbo].[crearIngresosPorMes]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[crearIngresosPorMes](@fechaAnalisis DATETIME)
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM INGRESO I JOIN MES M on I.fechaAnalisis = M.fechaAnalisis WHERE I.fechaAnalisis = @fechaAnalisis)
        INSERT INTO INGRESO (mes, fechaAnalisis, tipo)
        VALUES
            ('Mes 1', @fechaAnalisis, 'contado'), ('Mes 2', @fechaAnalisis, 'contado'), ('Mes 3', @fechaAnalisis, 'contado'),
            ('Mes 4', @fechaAnalisis, 'contado'), ('Mes 5', @fechaAnalisis, 'contado'), ('Mes 6', @fechaAnalisis, 'contado'),
            ('Mes 1', @fechaAnalisis, 'credito'), ('Mes 2', @fechaAnalisis, 'credito'), ('Mes 3', @fechaAnalisis, 'credito'),
            ('Mes 4', @fechaAnalisis, 'credito'), ('Mes 5', @fechaAnalisis, 'credito'), ('Mes 6', @fechaAnalisis, 'credito'),
            ('Mes 1', @fechaAnalisis, 'otros'), ('Mes 2', @fechaAnalisis, 'otros'), ('Mes 3', @fechaAnalisis, 'otros'),
            ('Mes 4', @fechaAnalisis, 'otros'), ('Mes 5', @fechaAnalisis, 'otros'), ('Mes 6', @fechaAnalisis, 'otros');
END
GO
/****** Object:  StoredProcedure [dbo].[crearMesesDeAnalisis]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[crearMesesDeAnalisis](@fechaAnalisis DATETIME)
AS
BEGIN
	IF NOT EXISTS (SELECT * FROM MES M JOIN ANALISIS A on M.fechaAnalisis = A.fechaCreacion WHERE M.fechaAnalisis = @fechaAnalisis)
		INSERT INTO MES (nombre, fechaAnalisis, inversionPorMes)
		VALUES
			('Mes1', @fechaAnalisis, 0.0),
			('Mes2', @fechaAnalisis, 0.0),
			('Mes3', @fechaAnalisis, 0.0),
			('Mes4', @fechaAnalisis, 0.0),
			('Mes5', @fechaAnalisis, 0.0),
			('Mes6', @fechaAnalisis, 0.0);
END
GO
/****** Object:  StoredProcedure [dbo].[EliminarAnalisis]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create PROCEDURE [dbo].[EliminarAnalisis] @fechaCreacion datetime
AS
DELETE FROM ANALISIS WHERE fechaCreacion=@fechaCreacion 
GO
/****** Object:  StoredProcedure [dbo].[eliminarGastoFijo]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[eliminarGastoFijo] (
	@nombreGastoFijo varchar(30),
	@fechaAnalisis datetime
)
AS
BEGIN
    Delete from GASTO_FIJO
	where GASTO_FIJO.fechaAnalisis = @fechaAnalisis 
		and GASTO_FIJO.nombre = @nombreGastoFijo
END;

-- Fabian Orozco Chaves | B95690
GO
/****** Object:  StoredProcedure [dbo].[EliminarGastoInicial]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[EliminarGastoInicial] (@fechaAnalisis datetime, @nombre varchar(30)) as
begin
	Delete from INVERSION_INICIAL where nombre=@nombre and fechaAnalisis=@fechaAnalisis
end

-- Christopher Perez Blanco | C05881
GO
/****** Object:  StoredProcedure [dbo].[EliminarProducto]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create procedure [dbo].[EliminarProducto] (@nombreProducto varchar(30), @fechaAnalisis datetime) as
Begin 
Delete from Producto where nombre=@nombreProducto and fechaAnalisis=@fechaAnalisis
end 


-- Fabian Orozco Chaves | B95690
GO
/****** Object:  StoredProcedure [dbo].[IngresarGastoInicial]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[IngresarGastoInicial] ( @fechaAnalisis datetime, @nombre varchar(30), @valor decimal(18,2)) as
begin
	SET @valor = REPLACE(@valor, ',', '.')
	insert into INVERSION_INICIAL values (@fechaAnalisis, @nombre, dbo.convertTOdecimal(@valor))
end

-- se hizo en conjunto con todos los integrantes
GO
/****** Object:  StoredProcedure [dbo].[IngresarNegocio]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE   procedure [dbo].[IngresarNegocio](
	@nextID int,
	@nombre varchar(30),
	@idUsuario nvarchar(450),
	@fechaCreacion datetime
)
as
begin 
	set transaction isolation level read uncommitted
	begin try
		begin transaction IngresarNegocio
		INSERT INTO Negocio (ID,Nombre,idUsuario,FechaCreacion) VALUES (@nextID, @nombre, @idUsuario, @fechaCreacion);
		commit transaction IngresarNegocio
	end try
	begin catch
		rollback transaction IngresarNegocio
	end catch
end

-- Daniel Escobar Giraldo | C02748
GO
/****** Object:  StoredProcedure [dbo].[insertarConfiguracionAnalisis]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE   procedure [dbo].[insertarConfiguracionAnalisis](
	@fechaAnalisis datetime,
	@procentajeSS decimal(5,2),
	@procentajePL decimal(5,2)
)
as 
begin 

    if @procentajeSS >= 0 
    begin 
	    update CONFIGURACION 
	    set porcentajeSS= @procentajeSS
	    where CONFIGURACION.fechaAnalisis=@fechaAnalisis
    end

    if @procentajePL >= 0 
    begin 
        update CONFIGURACION 
	    set porcentajePL = @procentajePL
	    where CONFIGURACION.fechaAnalisis=@fechaAnalisis
    end
end

-- Fabian Orozco Chaves | B95690
GO
/****** Object:  StoredProcedure [dbo].[insertarGastoFijo]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE procedure [dbo].[insertarGastoFijo] (
	@nombreAnterior varchar(30),
	@nombreGastoFijo varchar(30),
	@fechaAnalisis datetime,
	@monto varchar(30),
	@orden int
)
as 
BEGIN
	SET @monto = REPLACE(@monto, ',', '.')
	if exists (select GASTO_FIJO.nombre from GASTO_FIJO
		where GASTO_FIJO.fechaAnalisis = @fechaAnalisis and nombre=@nombreAnterior )
	BEGIN
		update GASTO_FIJO
		set GASTO_FIJO.nombre = @nombreGastoFijo, GASTO_FIJO.fechaAnalisis = @fechaAnalisis,  GASTO_FIJO.monto = dbo.convertTOdecimal(@monto), GASTO_FIJO.orden = @orden
		where GASTO_FIJO.fechaAnalisis = @fechaAnalisis and nombre=@nombreAnterior
	end
	ELSE
	begin
		insert into GASTO_FIJO values (@nombreGastoFijo, @fechaAnalisis, dbo.convertTOdecimal(@monto), @orden)
	end
END;

-- Christopher Perez Blanco | C05881
GO
/****** Object:  StoredProcedure [dbo].[InsertarProducto]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[InsertarProducto] 
(@nombreProducto varchar(30), @nombreAnterior varchar(30), @fechaAnalisis datetime, @lote int, 
@porcentajeDeVentas decimal(18,2), @precio decimal(18,2), @costoVariable decimal(18, 2), @comisionDeVentas decimal(18, 2)) as 
begin
if exists (Select PRODUCTO.nombre from Producto 
where @nombreAnterior=PRODUCTO.nombre and @fechaAnalisis=PRODUCTO.fechaAnalisis)
	begin 
		update Producto set nombre=@nombreProducto, lote=@lote, porcentajeDeVentas=@porcentajeDeVentas, precio=@precio, costoVariable=@costoVariable, comisionDeVentas=@comisionDeVentas
		where nombre=@nombreAnterior and fechaAnalisis=@fechaAnalisis
	end
else 
	begin
		insert into Producto values(@nombreProducto, @fechaAnalisis, @lote, @porcentajeDeVentas, @precio, @costoVariable, @comisionDeVentas)
	end
end

-- Christopher Perez Blanco | C05881
GO
/****** Object:  StoredProcedure [dbo].[ObtenerComponentes]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Procedure [dbo].[ObtenerComponentes] (@nombreProducto varchar(30), @fechaAnalisis datetime)
as 
Begin
SELECT * from COMPONENTE where nombreProducto=@nombreProducto and fechaAnalisis=@fechaAnalisis
End

-- Daniel Escobar Giraldo | C02748
GO
/****** Object:  StoredProcedure [dbo].[ObtenerConfigAnalisis]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[ObtenerConfigAnalisis](
	@fechaAnalisis Datetime
)
as 
begin 
	select fechaAnalisis, tipoNegocio, ISNULL(porcentajeSS, 0) as porcentajeSS, ISNULL(porcentajePL,0) as porcentajePL from Configuracion where fechaAnalisis = @fechaAnalisis
end
GO
/****** Object:  StoredProcedure [dbo].[ObtenerEgresosMes]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[ObtenerEgresosMes] @fechaAnalisis datetime , @nombreMes varchar(10)
as 
select * from EGRESO where fechaAnalisis = @fechaAnalisis and mes = @nombreMes

-- Fabian Orozco Chaves | B95690
GO
/****** Object:  StoredProcedure [dbo].[ObtenerGastosIniciales]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[ObtenerGastosIniciales] ( @fechaAnalisis datetime ) as
begin
	SELECT * FROM INVERSION_INICIAL WHERE fechaAnalisis=@fechaAnalisis order by nombre ASC
end
GO
/****** Object:  StoredProcedure [dbo].[ObtenerIngresosMes]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[ObtenerIngresosMes] @fechaAnalisis datetime , @nombreMes varchar(10)
as 
select * from INGRESO where fechaAnalisis = @fechaAnalisis and mes = @nombreMes

-- Daniel Escobar Giraldo | C02748
GO
/****** Object:  StoredProcedure [dbo].[ObtenerNegocioDeAnalisis]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[ObtenerNegocioDeAnalisis] (@fechaAnalisis DATETIME)
AS
BEGIN
    SELECT N.id, N.nombre, N.idUsuario, N.FechaCreacion 
    FROM NEGOCIO AS N JOIN ANALISIS AS A ON N.id = A.idNegocio
    WHERE A.fechaCreacion = @fechaAnalisis
END

-- Se hizo en llamada con todos los integrantes
GO
/****** Object:  StoredProcedure [dbo].[ObtenerNegocios]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE   procedure [dbo].[ObtenerNegocios](
	@idUsuario varchar(450)
)
as
begin 
	set transaction isolation level read committed
	begin try
		begin transaction ObtenerNegociosUsuario
		SELECT * FROM Negocio where idUsuario = @idUsuario ORDER BY FechaCreacion DESC
		commit transaction ObtenerNegociosUsuario
	end try
	begin catch
		rollback transaction ObtenerNegociosUsuario
	end catch
end

-- Wilmer Araya Rivas | B80538
GO
/****** Object:  StoredProcedure [dbo].[ObtenerPorcentajeDeVentasTotal]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[ObtenerPorcentajeDeVentasTotal] (@fechaAnalisis Datetime)
AS
BEGIN
	SELECT SUM(porcentajeDeVentas) totalPorcentajeVentas
	FROM PRODUCTO
	WHERE fechaAnalisis = @fechaAnalisis
END

-- Wilmer Araya Rivas | B80538
GO
/****** Object:  StoredProcedure [dbo].[ObtenerPorcentajeVentas]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[ObtenerPorcentajeVentas] (@fechaAnalisis Datetime, @nombreProducto varchar(30))
AS
BEGIN
	SELECT porcentajeDeVentas
	FROM PRODUCTO
	WHERE fechaAnalisis = @fechaAnalisis AND nombre = @nombreProducto
END


-- Christopher Perez Blanco | C05881
GO
/****** Object:  StoredProcedure [dbo].[ObtenerProductos]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[ObtenerProductos] (
	@fechaAnalisis datetime
)
as
begin 
SELECT * FROM PRODUCTO WHERE fechaAnalisis=@fechaAnalisis ORDER BY nombre ASC
end

-- Daniel Escobar Giraldo | C02748
GO
/****** Object:  StoredProcedure [dbo].[ObtenerPuestos]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[ObtenerPuestos] (
	@fechaAnalisis datetime
)
as
begin 
SELECT * FROM PUESTO WHERE fechaAnalisis=@fechaAnalisis order by orden ASC
end

-- Fabian Orozco Chaves | B95690
GO
/****** Object:  StoredProcedure [dbo].[ObtenerSumInversionInicial]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[ObtenerSumInversionInicial] ( @fechaAnalisis Datetime) as
begin
	Select SUM(valor) total from INVERSION_INICIAL where fechaAnalisis = @fechaAnalisis
end
GO
/****** Object:  StoredProcedure [dbo].[obtGastosFijosList]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[obtGastosFijosList] (@fechaAnalisis DATETIME) AS
BEGIN
	SELECT * FROM GASTO_FIJO
	WHERE GASTO_FIJO.fechaAnalisis = @fechaAnalisis
	ORDER BY GASTO_FIJO.nombre ASC
END

-- Fabian Orozco Chaves | B95690
GO
/****** Object:  StoredProcedure [dbo].[obtNombreNegocio]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[obtNombreNegocio] (@fechaAnalisis DATETIME) AS
BEGIN
SELECT DISTINCT NEGOCIO.nombre 
FROM NEGOCIO JOIN ANALISIS ON NEGOCIO.id = ANALISIS.idNegocio 
WHERE ANALISIS.fechaCreacion = @fechaAnalisis
END

-- Fabian Orozco Chaves | B95690
GO
/****** Object:  StoredProcedure [dbo].[obtNombreNegocioPorID]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create procedure [dbo].[obtNombreNegocioPorID] (@IDNegocio INT) as
begin
	SELECT negocio.nombre from dbo.negocio where negocio.ID = @IDNegocio
end

-- Fabian Orozco Chaves | B95690
GO
/****** Object:  StoredProcedure [dbo].[obtSumGastosFijos]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[obtSumGastosFijos] (@fechaAnalisis DATETIME) AS
BEGIN 
SELECT SUM(GASTO_FIJO.monto) totalAnual
FROM GASTO_FIJO WHERE GASTO_FIJO.fechaAnalisis = @fechaAnalisis
END

----------------------------------------------------
-- triggers
----------------------------------------------------

GO
/****** Object:  Trigger [dbo].[CrearMesesAnalisis]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE trigger [dbo].[CrearMesesAnalisis]
on [dbo].[ANALISIS] after insert
as
declare  @fechaAnalisis datetime
select @fechaAnalisis = i.fechaCreacion from inserted as i

insert into mes values ('Mes 1', @fechaAnalisis, 0.0);
insert into mes values ('Mes 2', @fechaAnalisis, 0.0);
insert into mes values ('Mes 3', @fechaAnalisis, 0.0);
insert into mes values ('Mes 4', @fechaAnalisis, 0.0);
insert into mes values ('Mes 5', @fechaAnalisis, 0.0);
insert into mes values ('Mes 6', @fechaAnalisis, 0.0);
GO
ALTER TABLE [dbo].[ANALISIS] ENABLE TRIGGER [CrearMesesAnalisis]


-- Gabriel Bonilla Rivera | C01252
GO
/****** Object:  Trigger [dbo].[ActualizarCostoVariable_DeleteComponente]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE trigger [dbo].[ActualizarCostoVariable_DeleteComponente]
on [dbo].[COMPONENTE] after delete
as
declare @nomProd varchar(30), @fecha datetime
declare c2 cursor for select d.nombreProducto, d.fechaAnalisis from deleted as d
open c2
fetch next from c2 into @nomProd, @fecha
while @@FETCH_STATUS = 0
	begin
		exec CostoVariableTotal @nombreProducto = @nomProd, @fechaAnalisis = @fecha
		fetch next from c2 into @nomProd, @fecha
	end
close c2
deallocate c2
GO
ALTER TABLE [dbo].[COMPONENTE] ENABLE TRIGGER [ActualizarCostoVariable_DeleteComponente]

-- Gabriel Bonilla Rivera | C01252
GO
/****** Object:  Trigger [dbo].[ActualizarCostoVariable_UpdateComponente]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE trigger [dbo].[ActualizarCostoVariable_UpdateComponente]
on [dbo].[COMPONENTE] after update, insert
as
declare @nomProd varchar(30), @fecha datetime
declare c3 cursor for select i.nombreProducto, i.fechaAnalisis from inserted as i
open c3
fetch next from c3 into @nomProd, @fecha
while @@FETCH_STATUS = 0
	begin
		exec CostoVariableTotal @nombreProducto = @nomProd, @fechaAnalisis = @fecha
		fetch next from c3 into @nomProd, @fecha
	end
close c3
deallocate c3
GO
ALTER TABLE [dbo].[COMPONENTE] ENABLE TRIGGER [ActualizarCostoVariable_UpdateComponente]


-- Gabriel Bonilla Rivera | C01252
GO
/****** Object:  Trigger [dbo].[ActualizarCostoVariable_UpdateLote]    Script Date: 28/11/2022 11:01:32 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE trigger [dbo].[ActualizarCostoVariable_UpdateLote] 
on [dbo].[PRODUCTO] after update
as
declare @nomProd varchar(30), @fecha datetime
set @nomProd = (select i.nombre from inserted as i)
print @nomProd
set @fecha = (select i.fechaAnalisis from inserted as i)
print @fecha

if (update (lote))
begin
	exec CostoVariableTotal @nombreProducto = @nomProd, @fechaAnalisis = @fecha
end
GO
ALTER TABLE [dbo].[PRODUCTO] ENABLE TRIGGER [ActualizarCostoVariable_UpdateLote]
GO
USE [master]
GO
ALTER DATABASE [Wumpus_PROD] SET  READ_WRITE 
GO

----------------------------------------------------
-- funciones
----------------------------------------------------
use Wumpus_PROD
GO
/****** Object:  UserDefinedFunction [dbo].[convertTOdecimal]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON

-- Wilmer Araya Rivas | B80538
GO
CREATE FUNCTION [dbo].[convertTOdecimal] (@num varchar(20))
RETURNS DEC(18,3) AS
BEGIN
	DECLARE @Result DEC(18,3)
	SELECT @Result = CAST(@num AS DECIMAL(18,3))
	RETURN @Result
END

-- Wilmer Araya Rivas | B80538
GO
/****** Object:  UserDefinedFunction [dbo].[obtGastoPrestaciones]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE FUNCTION [dbo].[obtGastoPrestaciones] (@fechaAnalisis DATETIME, @porcentaje DEC(6,3))
RETURNS DEC(18,3) AS
BEGIN
	DECLARE @Result DEC(18,3)
	SELECT @Result = dbo.obtSumSalarios (@fechaAnalisis) * @porcentaje
	RETURN @Result
END

-- Wilmer Araya Rivas | B80538
GO
/****** Object:  UserDefinedFunction [dbo].[obtGastoSeguroSocial]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE FUNCTION [dbo].[obtGastoSeguroSocial] (@fechaAnalisis DATETIME, @porcentaje DEC(6,3))
RETURNS DEC(18,3) AS
BEGIN
	DECLARE @Result DEC(18,3)
	SELECT @Result = dbo.obtSumSalarios (@fechaAnalisis) * @porcentaje
	RETURN @Result
END
GO
/****** Object:  UserDefinedFunction [dbo].[obtSumSalarios]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON


-- Wilmer Araya Rivas | B80538
GO
CREATE FUNCTION [dbo].[obtSumSalarios] (@fechaAnalisis DATETIME)
RETURNS DEC(18,3) AS
BEGIN
	DECLARE @totalSalarios DEC(18,3)
	IF EXISTS (SELECT * FROM PUESTO P WHERE P.fechaAnalisis = @fechaAnalisis)
		SELECT @totalSalarios = SUM(P.cantidadPlazas * P.SalarioBruto)
		FROM PUESTO P
		WHERE P.fechaAnalisis = @fechaAnalisis
	ELSE
		RETURN 0
	RETURN @totalSalarios * 12
END
GO
/****** Object:  UserDefinedFunction [dbo].[obtTotalBeneficios]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON

-- Wilmer Araya Rivas | B80538
GO
CREATE FUNCTION [dbo].[obtTotalBeneficios] (@fechaAnalisis DATETIME)
RETURNS DEC(18,3) AS
BEGIN
	DECLARE @Result DEC(18,3)
		SELECT @Result = SUM(PUESTO.beneficios * PUESTO.cantidadPlazas)
		FROM Puesto
		WHERE Puesto.fechaAnalisis = @fechaAnalisis
	RETURN @Result *12
END


-- Wilmer Araya Rivas | B80538
GO
/****** Object:  UserDefinedFunction [dbo].[obtTotalSalariosNeto]    Script Date: 28/11/2022 11:01:31 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE FUNCTION [dbo].[obtTotalSalariosNeto] (@fechaAnalisis DATETIME, @seguroSocial DEC(6,3), @prestaciones DEC(6,3))
RETURNS DEC(18,3) AS
BEGIN
	DECLARE @Result DEC(18,3)
	SELECT @Result = dbo.obtSumSalarios (@fechaAnalisis) - dbo.obtGastoSeguroSocial(@fechaAnalisis,@seguroSocial) - dbo.obtGastoPrestaciones(@fechaAnalisis,@prestaciones)
	RETURN @Result
END