import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import {RouterModule, Routes} from '@angular/router';

const routes: Routes =
  [
    {
      path: 'take-bets',
      loadChildren: './taker/taker.module#TakerModule'
    },
    {
      path: 'make-bets',
      loadChildren: './maker/maker.module#MakerModule'
    },
    {
      path: 'collect',
      loadChildren: './collect/collect.module#CollectModule'
    },
    {
      path: '',
      redirectTo: 'make-bets',
      pathMatch: 'full'
    }
    // TODO add page not found component
    // { path: '**', component: PageNotFoundComponent }
  ];

@NgModule({
  imports: [
    CommonModule,
    RouterModule.forRoot(routes,  { enableTracing: true })
  ],
  exports: [ RouterModule ]
})
export class AppRoutingModule { }
