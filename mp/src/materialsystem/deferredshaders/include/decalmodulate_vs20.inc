// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// ( $DOWATERFOG == 0 ) && ( $DOPIXELFOG && $HARDWAREFOGBLEND )
// ( $DOWATERFOG == 0 ) && ( $HARDWAREFOGBLEND == 0 ) && ( $DOPIXELFOG == 0 )
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH

#pragma once
#include "shaderlib/cshader.h"
class decalmodulate_vs20_Static_Index
{
	unsigned int m_nVERTEXCOLOR : 2;
	unsigned int m_nDOPIXELFOG : 2;
	unsigned int m_nHARDWAREFOGBLEND : 2;
#ifdef _DEBUG
	bool m_bVERTEXCOLOR : 1;
#endif	// _DEBUG
public:
	void SetVERTEXCOLOR( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nVERTEXCOLOR = i;
#ifdef _DEBUG
		m_bVERTEXCOLOR = true;
#endif	// _DEBUG
	}

	void SetDOPIXELFOG( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDOPIXELFOG = i;
	}

	void SetHARDWAREFOGBLEND( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nHARDWAREFOGBLEND = i;
	}

	decalmodulate_vs20_Static_Index(  )
	{
		m_nVERTEXCOLOR = 0;
		m_nDOPIXELFOG = g_pHardwareConfig->SupportsPixelShaders_2_b() ;
		m_nHARDWAREFOGBLEND = !g_pHardwareConfig->SupportsPixelShaders_2_b() ;
#ifdef _DEBUG
		m_bVERTEXCOLOR = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bVERTEXCOLOR );
		return ( 16 * m_nVERTEXCOLOR ) + ( 32 * m_nDOPIXELFOG ) + ( 64 * m_nHARDWAREFOGBLEND ) + 0;
	}
};

#define shaderStaticTest_decalmodulate_vs20 vsh_forgot_to_set_static_VERTEXCOLOR


class decalmodulate_vs20_Dynamic_Index
{
	unsigned int m_nCOMPRESSED_VERTS : 2;
	unsigned int m_nDOWATERFOG : 2;
	unsigned int m_nSKINNING : 2;
	unsigned int m_nLIGHTING_PREVIEW : 2;
#ifdef _DEBUG
	bool m_bCOMPRESSED_VERTS : 1;
	bool m_bSKINNING : 1;
	bool m_bLIGHTING_PREVIEW : 1;
#endif	// _DEBUG
public:
	void SetCOMPRESSED_VERTS( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nCOMPRESSED_VERTS = i;
#ifdef _DEBUG
		m_bCOMPRESSED_VERTS = true;
#endif	// _DEBUG
	}

	void SetDOWATERFOG( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDOWATERFOG = i;
	}

	void SetSKINNING( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSKINNING = i;
#ifdef _DEBUG
		m_bSKINNING = true;
#endif	// _DEBUG
	}

	void SetLIGHTING_PREVIEW( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nLIGHTING_PREVIEW = i;
#ifdef _DEBUG
		m_bLIGHTING_PREVIEW = true;
#endif	// _DEBUG
	}

	decalmodulate_vs20_Dynamic_Index(  )
	{
		m_nCOMPRESSED_VERTS = 0;
		m_nDOWATERFOG = ( pShaderAPI->GetSceneFogMode() == MATERIAL_FOG_LINEAR_BELOW_FOG_Z ) ;
		m_nSKINNING = 0;
		m_nLIGHTING_PREVIEW = 0;
#ifdef _DEBUG
		m_bCOMPRESSED_VERTS = false;
		m_bSKINNING = false;
		m_bLIGHTING_PREVIEW = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bCOMPRESSED_VERTS && m_bSKINNING && m_bLIGHTING_PREVIEW );
		return ( 1 * m_nCOMPRESSED_VERTS ) + ( 2 * m_nDOWATERFOG ) + ( 4 * m_nSKINNING ) + ( 8 * m_nLIGHTING_PREVIEW ) + 0;
	}
};

#define shaderDynamicTest_decalmodulate_vs20 vsh_forgot_to_set_dynamic_COMPRESSED_VERTS + vsh_forgot_to_set_dynamic_SKINNING + vsh_forgot_to_set_dynamic_LIGHTING_PREVIEW

