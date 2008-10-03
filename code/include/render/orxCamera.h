/* Orx - Portable Game Engine
 *
 * Orx is the legal property of its developers, whose names
 * are listed in the COPYRIGHT file distributed 
 * with this source distribution.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/**
 * @file orxCamera.h
 * @date 10/12/2003
 * @author iarwain@orx-project.org
 *
 * @todo
 */

/**
 * @addtogroup orxCamera
 * 
 * Camera Module
 * Allows to creates and handle cameras
 * Camera are structures used to render graphic (2D/3D) objects
 * They thus can be referenced by other structures
 *
 * @{
 */


#ifndef _orxCAMERA_H_
#define _orxCAMERA_H_


#include "orxInclude.h"

#include "object/orxFrame.h"
#include "math/orxAABox.h"


/** Anim flags
 */
#define orxCAMERA_KU32_FLAG_NONE              0x00000000 /**< No flags */

#define orxCAMERA_KU32_FLAG_2D                0x00000001 /**< 2D flag */

#define orxCAMERA_KU32_MASK_USER_ALL          0x000000FF /**< User all mask */


/** Internal camera structure
 */
typedef struct __orxCAMERA_t            orxCAMERA;


/** Camera module setup
 */
extern orxDLLAPI orxVOID                orxCamera_Setup();

/** Inits the Camera module
 */
extern orxDLLAPI orxSTATUS              orxCamera_Init();

/** Exits from the Camera module
 */
extern orxDLLAPI orxVOID                orxCamera_Exit();


/** Creates a camera
 * @param[in]   _u32Flags               Camera flags (2D / ...)
 * @return      Created orxCAMERA / orxNULL
 */
extern orxDLLAPI orxCAMERA *orxFASTCALL orxCamera_Create(orxU32 _u32Flags);

/** Creates a camera from config
 * @param[in]   _zConfigID    Config ID
 * @ return orxCAMERA / orxNULL
 */
extern orxDLLAPI orxCAMERA *orxFASTCALL orxCamera_CreateFromConfig(orxCONST orxSTRING _zConfigID);

/** Deletes a camera
 * @param[in]   _pstCamera      Camera to delete
 * @return      orxSTATUS_SUCCESS / orxSTATUS_FAILURE
 */
extern orxDLLAPI orxSTATUS orxFASTCALL  orxCamera_Delete(orxCAMERA *_pstCamera);


/** Sets camera frustum
 * @param[in]   _pstCamera      Concerned camera
 * @param[in]   _fWidth         Width of frustum
 * @param[in]   _fHeight        Height of frustum
 * @param[in]   _fNear          Near distance of frustum
 * @param[in]   _fFar           Far distance of frustum
 * @return      orxSTATUS_SUCCESS / orxSTATUS_FAILURE
 */
extern orxDLLAPI orxSTATUS orxFASTCALL  orxCamera_SetFrustum(orxCAMERA *_pstCamera, orxFLOAT _fWidth, orxFLOAT _fHeight, orxFLOAT _fNear, orxFLOAT _fFar);

/** Sets camera position
 * @param[in]   _pstCamera      Concerned camera
 * @param[in]   _pvPosition     Camera position
 * @return      orxSTATUS_SUCCESS / orxSTATUS_FAILURE
 */
extern orxDLLAPI orxSTATUS orxFASTCALL  orxCamera_SetPosition(orxCAMERA *_pstCamera, orxCONST orxVECTOR *_pvPosition);

/** Sets camera rotation
 * @param[in]   _pstCamera      Concerned camera
 * @param[in]   _fRotation      Camera rotation
 * @return      orxSTATUS_SUCCESS / orxSTATUS_FAILURE
 */
extern orxDLLAPI orxSTATUS orxFASTCALL  orxCamera_SetRotation(orxCAMERA *_pstCamera, orxFLOAT _fRotation);

/** Sets camera zoom
 * @param[in]   _pstCamera      Concerned camera
 * @param[in]   _fZoom          Camera zoom
 * @return      orxSTATUS_SUCCESS / orxSTATUS_FAILURE
 */
extern orxDLLAPI orxSTATUS orxFASTCALL  orxCamera_SetZoom(orxCAMERA *_pstCamera, orxFLOAT _fZoom);

/** Gets camera frustum (3D box for 2D camera)
 * @param[in]   _pstCamera      Concerned camera
 * @param[out]  _pstFrustum    Frustum box
 */
extern orxDLLAPI orxVOID orxFASTCALL    orxCamera_GetFrustum(orxCONST orxCAMERA *_pstCamera, orxAABOX *_pstFrustum);

/** Get camera position
 * @param[in]   _pstCamera      Concerned camera
 * @param[out]  _pvPosition     Camera position
 * @return      orxVECTOR
 */
extern orxDLLAPI orxVECTOR *orxFASTCALL orxCamera_GetPosition(orxCONST orxCAMERA *_pstCamera, orxVECTOR *_pvPosition);

/** Get camera rotation
 * @param[in]   _pstCamera      Concerned camera
 * @return      Rotation value
 */
extern orxDLLAPI orxFLOAT orxFASTCALL   orxCamera_GetRotation(orxCONST orxCAMERA *_pstCamera);

/** Get camera zoom
 * @param[in]   _pstCamera      Concerned camera
 * @return      Zoom value
 */
extern orxDLLAPI orxFLOAT orxFASTCALL   orxCamera_GetZoom(orxCONST orxCAMERA *_pstCamera);


/** Gets camera frame
 * @param[in]   _pstCamera      Concerned camera
 * @return      orxFRAME
 */
extern orxDLLAPI orxFRAME *orxFASTCALL  orxCamera_GetFrame(orxCONST orxCAMERA *_pstCamera);

/** Sets camera parent
 * @param[in]   _pstCamera      Concerned camera
 * @param[in]   _pParent        Parent structure to set (object, spawner, camera or frame) / orxNULL
 * @return      orsSTATUS_SUCCESS / orxSTATUS_FAILURE
 */
extern orxDLLAPI orxSTATUS orxFASTCALL  orxCamera_SetParent(orxCAMERA *_pstCamera, orxVOID *_pParent);

#endif /* _orxCAMERA_H_ */

/** @} */
