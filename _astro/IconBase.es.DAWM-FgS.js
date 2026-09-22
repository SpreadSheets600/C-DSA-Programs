import{r as i}from"./index.u1LLWZlj.js";var x={exports:{}},s={};/**
 * @license React
 * react-jsx-runtime.production.js
 *
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */var d;function h(){if(d)return s;d=1;var u=Symbol.for("react.transitional.element"),a=Symbol.for("react.fragment");function t(l,r,e){var o=null;if(e!==void 0&&(o=""+e),r.key!==void 0&&(o=""+r.key),"key"in r){e={};for(var n in r)n!=="key"&&(e[n]=r[n])}else e=r;return r=e.ref,{$$typeof:u,type:l,key:o,ref:r!==void 0?r:null,props:e}}return s.Fragment=a,s.jsx=t,s.jsxs=t,s}var m;function _(){return m||(m=1,x.exports=h()),x.exports}var C=_();const g=i.createContext({color:"currentColor",size:"1em",weight:"regular",mirrored:!1}),j=i.forwardRef((u,a)=>{const{alt:t,color:l,size:r,weight:e,mirrored:o,children:n,weights:v,...R}=u,{color:f="currentColor",size:c,weight:p="regular",mirrored:w=!1,...E}=i.useContext(g);return i.createElement("svg",{ref:a,xmlns:"http://www.w3.org/2000/svg",width:r??c,height:r??c,fill:l??f,viewBox:"0 0 256 256",transform:o||w?"scale(-1, 1)":void 0,...E,...R},!!t&&i.createElement("title",null,t),n,v.get(e??p))});j.displayName="IconBase";export{C as j,j as p};
